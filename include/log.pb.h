// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: log.proto

#ifndef PROTOBUF_log_2eproto__INCLUDED
#define PROTOBUF_log_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace rpc_log {
class Student;
class StudentDefaultTypeInternal;
extern StudentDefaultTypeInternal _Student_default_instance_;
class Teacher;
class TeacherDefaultTypeInternal;
extern TeacherDefaultTypeInternal _Teacher_default_instance_;
}  // namespace rpc_log

namespace rpc_log {

namespace protobuf_log_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_log_2eproto

// ===================================================================

class Teacher : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rpc_log.Teacher) */ {
 public:
  Teacher();
  virtual ~Teacher();

  Teacher(const Teacher& from);

  inline Teacher& operator=(const Teacher& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Teacher& default_instance();

  static inline const Teacher* internal_default_instance() {
    return reinterpret_cast<const Teacher*>(
               &_Teacher_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Teacher* other);

  // implements Message ----------------------------------------------

  inline Teacher* New() const PROTOBUF_FINAL { return New(NULL); }

  Teacher* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Teacher& from);
  void MergeFrom(const Teacher& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Teacher* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string unique_name = 1;
  bool has_unique_name() const;
  void clear_unique_name();
  static const int kUniqueNameFieldNumber = 1;
  const ::std::string& unique_name() const;
  void set_unique_name(const ::std::string& value);
  #if LANG_CXX11
  void set_unique_name(::std::string&& value);
  #endif
  void set_unique_name(const char* value);
  void set_unique_name(const char* value, size_t size);
  ::std::string* mutable_unique_name();
  ::std::string* release_unique_name();
  void set_allocated_unique_name(::std::string* unique_name);

  // required string name = 2;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required int32 age = 3;
  bool has_age() const;
  void clear_age();
  static const int kAgeFieldNumber = 3;
  ::google::protobuf::int32 age() const;
  void set_age(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:rpc_log.Teacher)
 private:
  void set_has_unique_name();
  void clear_has_unique_name();
  void set_has_name();
  void clear_has_name();
  void set_has_age();
  void clear_has_age();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr unique_name_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 age_;
  friend struct protobuf_log_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Student : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:rpc_log.Student) */ {
 public:
  Student();
  virtual ~Student();

  Student(const Student& from);

  inline Student& operator=(const Student& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Student& default_instance();

  static inline const Student* internal_default_instance() {
    return reinterpret_cast<const Student*>(
               &_Student_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(Student* other);

  // implements Message ----------------------------------------------

  inline Student* New() const PROTOBUF_FINAL { return New(NULL); }

  Student* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Student& from);
  void MergeFrom(const Student& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Student* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string unique_name = 1;
  bool has_unique_name() const;
  void clear_unique_name();
  static const int kUniqueNameFieldNumber = 1;
  const ::std::string& unique_name() const;
  void set_unique_name(const ::std::string& value);
  #if LANG_CXX11
  void set_unique_name(::std::string&& value);
  #endif
  void set_unique_name(const char* value);
  void set_unique_name(const char* value, size_t size);
  ::std::string* mutable_unique_name();
  ::std::string* release_unique_name();
  void set_allocated_unique_name(::std::string* unique_name);

  // required string name = 2;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required int32 age = 3;
  bool has_age() const;
  void clear_age();
  static const int kAgeFieldNumber = 3;
  ::google::protobuf::int32 age() const;
  void set_age(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:rpc_log.Student)
 private:
  void set_has_unique_name();
  void clear_has_unique_name();
  void set_has_name();
  void clear_has_name();
  void set_has_age();
  void clear_has_age();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr unique_name_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int32 age_;
  friend struct protobuf_log_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Teacher

// required string unique_name = 1;
inline bool Teacher::has_unique_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Teacher::set_has_unique_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Teacher::clear_has_unique_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Teacher::clear_unique_name() {
  unique_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_unique_name();
}
inline const ::std::string& Teacher::unique_name() const {
  // @@protoc_insertion_point(field_get:rpc_log.Teacher.unique_name)
  return unique_name_.GetNoArena();
}
inline void Teacher::set_unique_name(const ::std::string& value) {
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rpc_log.Teacher.unique_name)
}
#if LANG_CXX11
inline void Teacher::set_unique_name(::std::string&& value) {
  set_has_unique_name();
  unique_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rpc_log.Teacher.unique_name)
}
#endif
inline void Teacher::set_unique_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rpc_log.Teacher.unique_name)
}
inline void Teacher::set_unique_name(const char* value, size_t size) {
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rpc_log.Teacher.unique_name)
}
inline ::std::string* Teacher::mutable_unique_name() {
  set_has_unique_name();
  // @@protoc_insertion_point(field_mutable:rpc_log.Teacher.unique_name)
  return unique_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Teacher::release_unique_name() {
  // @@protoc_insertion_point(field_release:rpc_log.Teacher.unique_name)
  clear_has_unique_name();
  return unique_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Teacher::set_allocated_unique_name(::std::string* unique_name) {
  if (unique_name != NULL) {
    set_has_unique_name();
  } else {
    clear_has_unique_name();
  }
  unique_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), unique_name);
  // @@protoc_insertion_point(field_set_allocated:rpc_log.Teacher.unique_name)
}

// required string name = 2;
inline bool Teacher::has_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Teacher::set_has_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Teacher::clear_has_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Teacher::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Teacher::name() const {
  // @@protoc_insertion_point(field_get:rpc_log.Teacher.name)
  return name_.GetNoArena();
}
inline void Teacher::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rpc_log.Teacher.name)
}
#if LANG_CXX11
inline void Teacher::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rpc_log.Teacher.name)
}
#endif
inline void Teacher::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rpc_log.Teacher.name)
}
inline void Teacher::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rpc_log.Teacher.name)
}
inline ::std::string* Teacher::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:rpc_log.Teacher.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Teacher::release_name() {
  // @@protoc_insertion_point(field_release:rpc_log.Teacher.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Teacher::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:rpc_log.Teacher.name)
}

// required int32 age = 3;
inline bool Teacher::has_age() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Teacher::set_has_age() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Teacher::clear_has_age() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Teacher::clear_age() {
  age_ = 0;
  clear_has_age();
}
inline ::google::protobuf::int32 Teacher::age() const {
  // @@protoc_insertion_point(field_get:rpc_log.Teacher.age)
  return age_;
}
inline void Teacher::set_age(::google::protobuf::int32 value) {
  set_has_age();
  age_ = value;
  // @@protoc_insertion_point(field_set:rpc_log.Teacher.age)
}

// -------------------------------------------------------------------

// Student

// required string unique_name = 1;
inline bool Student::has_unique_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Student::set_has_unique_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Student::clear_has_unique_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Student::clear_unique_name() {
  unique_name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_unique_name();
}
inline const ::std::string& Student::unique_name() const {
  // @@protoc_insertion_point(field_get:rpc_log.Student.unique_name)
  return unique_name_.GetNoArena();
}
inline void Student::set_unique_name(const ::std::string& value) {
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rpc_log.Student.unique_name)
}
#if LANG_CXX11
inline void Student::set_unique_name(::std::string&& value) {
  set_has_unique_name();
  unique_name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rpc_log.Student.unique_name)
}
#endif
inline void Student::set_unique_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rpc_log.Student.unique_name)
}
inline void Student::set_unique_name(const char* value, size_t size) {
  set_has_unique_name();
  unique_name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rpc_log.Student.unique_name)
}
inline ::std::string* Student::mutable_unique_name() {
  set_has_unique_name();
  // @@protoc_insertion_point(field_mutable:rpc_log.Student.unique_name)
  return unique_name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Student::release_unique_name() {
  // @@protoc_insertion_point(field_release:rpc_log.Student.unique_name)
  clear_has_unique_name();
  return unique_name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Student::set_allocated_unique_name(::std::string* unique_name) {
  if (unique_name != NULL) {
    set_has_unique_name();
  } else {
    clear_has_unique_name();
  }
  unique_name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), unique_name);
  // @@protoc_insertion_point(field_set_allocated:rpc_log.Student.unique_name)
}

// required string name = 2;
inline bool Student::has_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Student::set_has_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Student::clear_has_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Student::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Student::name() const {
  // @@protoc_insertion_point(field_get:rpc_log.Student.name)
  return name_.GetNoArena();
}
inline void Student::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:rpc_log.Student.name)
}
#if LANG_CXX11
inline void Student::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:rpc_log.Student.name)
}
#endif
inline void Student::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:rpc_log.Student.name)
}
inline void Student::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:rpc_log.Student.name)
}
inline ::std::string* Student::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:rpc_log.Student.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Student::release_name() {
  // @@protoc_insertion_point(field_release:rpc_log.Student.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Student::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:rpc_log.Student.name)
}

// required int32 age = 3;
inline bool Student::has_age() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Student::set_has_age() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Student::clear_has_age() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Student::clear_age() {
  age_ = 0;
  clear_has_age();
}
inline ::google::protobuf::int32 Student::age() const {
  // @@protoc_insertion_point(field_get:rpc_log.Student.age)
  return age_;
}
inline void Student::set_age(::google::protobuf::int32 value) {
  set_has_age();
  age_ = value;
  // @@protoc_insertion_point(field_set:rpc_log.Student.age)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace rpc_log

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_log_2eproto__INCLUDED