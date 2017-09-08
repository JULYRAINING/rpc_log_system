

#include "include/log_buffer.h"

namespace logsystem_buffer
{

//静态缓冲区
std::map<std::string, std::vector<std::string>> LogBuffer::_buffers;
//缓冲区大小
int LogBuffer::_max_buffer_size = 3;

LogBuffer::LogBuffer()
{
    //初始化信号量
    sem_init(&binSem, 0, 0);
    sem_post(&binSem);

    std::string path_server = "/log";
    std::string path_client = "/local_log";
    init(path_server);
    init(path_client);
    LOG_DEBUG("初始化日志缓冲类");
}
LogBuffer::~LogBuffer(){
    LOG_DEBUG("销毁日志缓冲类");
}

LogBuffer::LogBuffer(int buffer_size)
{
    if (buffer_size <= 0)
    {
        _max_buffer_size = 30;
    }
    else
    {
        _max_buffer_size = buffer_size;
    }
    //初始化信号量
    sem_init(&binSem, 0, 0);
    sem_post(&binSem);
    LOG_DEBUG("初始化日志缓冲类");
}

//初始化日志存储目录
int LogBuffer::init(std::string path)
{

    if (!isExistFile(path))
    {
        const int dir_err = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        if (-1 == dir_err)
        {
            LOG_TRACE("日志存储目录创建失败");
            exit(1);
        }
        LOG_TRACE("日志存储目录创建成功");
    }
}

int LogBuffer::get_buffer_size()
{
    return _max_buffer_size;
}

std::vector<std::string> LogBuffer::read(std::string write_path, std::string filename)
{
    std::vector<std::string> local_logs;
    std::string absolute_filename = write_path + "/" + filename;
    char buffer[256];
    int res = 0;

    sem_wait(&binSem);
    LOG_TRACE("获得读取信号量");
    std::ifstream in(absolute_filename);
    int count = 1;
    if (!in.is_open())
    {
        LOG_TRACE("打开文件失败" + absolute_filename);
        // exit(1);
    }
    while (!in.eof())
    {
        in.getline(buffer, 100);
        local_logs.push_back(buffer);
        ++count;
    }
    //删除文件中的内容
    in.close();
    std::ofstream ofs;
    ofs.open(absolute_filename, std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    sem_post(&binSem);
    LOG_TRACE("读取信号量已释放");
    LOG_TRACE("读取了 " + std::to_string(count) + " 条日志信息");
    return local_logs;
}

int LogBuffer::write(std::string message, std::string write_path, std::string filename)
{
    //加入缓冲区
    _buffers[write_path + filename].push_back(message);

    //若缓冲区未满
    if (_buffers[write_path + filename].size() <= _max_buffer_size)
    {
        int size = _buffers[write_path + filename].size();
        LOG_TRACE("将日志加入 " + write_path + filename + " 缓冲区, 缓冲区大小: " + std::to_string(size) + "");

    } //若缓冲区已满
    else
    {
        //批量写入文件
        LOG_TRACE("刷新缓冲区日志, 缓冲区大小: " + _buffers[write_path + filename].size());
        write_to_file(write_path, filename);
    }
    return 0;
}

int LogBuffer::write_to_file(std::string write_path, std::string filename)
{

    init(write_path);
    //拼接字符串
    int len = _buffers[write_path + filename].size();
    std::string content;

    for (int i = 0; i < len; i++)
    {

        content.append(_buffers[write_path + filename][i]);
        content.append("\n");
    }
    LOG_TRACE("开始写入文件");
    //等待获得信号量
    sem_wait(&binSem);
    LOG_TRACE("获取写入信号量");

    // 写文件 加锁
    // LOG_TRACE("获取写入锁");
    // std::mutex mt;
    // mt.lock();
    // 清空缓冲区
    _buffers[write_path + filename].clear();

    std::ofstream log_file;

    //以append模式打开文件
    std::string file_absolute_name;
    file_absolute_name = write_path + "/" + filename;

    log_file.open(file_absolute_name, std::ios::app);
    if (log_file.is_open())
    {
        log_file << content;
        log_file.close();
        LOG_DEBUG("本地日志已写入, file : " + file_absolute_name);// + " content : " + content);
    }
    else
    {
        LOG_ERROR("文件打开失败");

        return -1;
    }
    // mt.unlock();
    // LOG_TRACE("写入锁已释放");
    //释放信号量
    sem_post(&binSem);
    LOG_DEBUG("写入信号量已释放");
    LOG_TRACE("文件写入完毕");
    return 0;
}

bool LogBuffer::isExistFile(std::string filename)
{
    FILE *fp = fopen(filename.c_str(), "rb");
    if (fp == NULL)
        return false;
    fclose(fp);
    return true;
}

std::vector<std::string> LogBuffer::split(std::string source, char sep)
{
    LOG_TRACE("系统已启动");
    std::stringstream ss;
    ss.str(source);
    std::string item;
    std::vector<std::string> result;
    while (std::getline(ss, item, sep))
    {
        // *(result++) = item;
        result.push_back(item);
    }
    return result;
}
}