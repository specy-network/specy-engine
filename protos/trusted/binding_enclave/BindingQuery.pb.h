// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BindingQuery.proto

#ifndef PROTOBUF_INCLUDED_BindingQuery_2eproto
#define PROTOBUF_INCLUDED_BindingQuery_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_BindingQuery_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_BindingQuery_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_BindingQuery_2eproto();
namespace request_proto {
class BindingQueryItem;
class BindingQueryItemDefaultTypeInternal;
extern BindingQueryItemDefaultTypeInternal _BindingQueryItem_default_instance_;
class BindingQueryMessage;
class BindingQueryMessageDefaultTypeInternal;
extern BindingQueryMessageDefaultTypeInternal _BindingQueryMessage_default_instance_;
}  // namespace request_proto
namespace google {
namespace protobuf {
template<> ::request_proto::BindingQueryItem* Arena::CreateMaybeMessage<::request_proto::BindingQueryItem>(Arena*);
template<> ::request_proto::BindingQueryMessage* Arena::CreateMaybeMessage<::request_proto::BindingQueryMessage>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace request_proto {

// ===================================================================

class BindingQueryItem :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:request_proto.BindingQueryItem) */ {
 public:
  BindingQueryItem();
  virtual ~BindingQueryItem();

  BindingQueryItem(const BindingQueryItem& from);

  inline BindingQueryItem& operator=(const BindingQueryItem& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BindingQueryItem(BindingQueryItem&& from) noexcept
    : BindingQueryItem() {
    *this = ::std::move(from);
  }

  inline BindingQueryItem& operator=(BindingQueryItem&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const BindingQueryItem& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BindingQueryItem* internal_default_instance() {
    return reinterpret_cast<const BindingQueryItem*>(
               &_BindingQueryItem_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(BindingQueryItem* other);
  friend void swap(BindingQueryItem& a, BindingQueryItem& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BindingQueryItem* New() const final {
    return CreateMaybeMessage<BindingQueryItem>(nullptr);
  }

  BindingQueryItem* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BindingQueryItem>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const BindingQueryItem& from);
  void MergeFrom(const BindingQueryItem& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BindingQueryItem* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string contractID = 1;
  void clear_contractid();
  static const int kContractIDFieldNumber = 1;
  const ::std::string& contractid() const;
  void set_contractid(const ::std::string& value);
  #if LANG_CXX11
  void set_contractid(::std::string&& value);
  #endif
  void set_contractid(const char* value);
  void set_contractid(const char* value, size_t size);
  ::std::string* mutable_contractid();
  ::std::string* release_contractid();
  void set_allocated_contractid(::std::string* contractid);

  // string contractBinding = 2;
  void clear_contractbinding();
  static const int kContractBindingFieldNumber = 2;
  const ::std::string& contractbinding() const;
  void set_contractbinding(const ::std::string& value);
  #if LANG_CXX11
  void set_contractbinding(::std::string&& value);
  #endif
  void set_contractbinding(const char* value);
  void set_contractbinding(const char* value, size_t size);
  ::std::string* mutable_contractbinding();
  ::std::string* release_contractbinding();
  void set_allocated_contractbinding(::std::string* contractbinding);

  // @@protoc_insertion_point(class_scope:request_proto.BindingQueryItem)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr contractid_;
  ::google::protobuf::internal::ArenaStringPtr contractbinding_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BindingQuery_2eproto;
};
// -------------------------------------------------------------------

class BindingQueryMessage :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:request_proto.BindingQueryMessage) */ {
 public:
  BindingQueryMessage();
  virtual ~BindingQueryMessage();

  BindingQueryMessage(const BindingQueryMessage& from);

  inline BindingQueryMessage& operator=(const BindingQueryMessage& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  BindingQueryMessage(BindingQueryMessage&& from) noexcept
    : BindingQueryMessage() {
    *this = ::std::move(from);
  }

  inline BindingQueryMessage& operator=(BindingQueryMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const BindingQueryMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const BindingQueryMessage* internal_default_instance() {
    return reinterpret_cast<const BindingQueryMessage*>(
               &_BindingQueryMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(BindingQueryMessage* other);
  friend void swap(BindingQueryMessage& a, BindingQueryMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline BindingQueryMessage* New() const final {
    return CreateMaybeMessage<BindingQueryMessage>(nullptr);
  }

  BindingQueryMessage* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<BindingQueryMessage>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const BindingQueryMessage& from);
  void MergeFrom(const BindingQueryMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(BindingQueryMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .request_proto.BindingQueryItem items = 1;
  int items_size() const;
  void clear_items();
  static const int kItemsFieldNumber = 1;
  ::request_proto::BindingQueryItem* mutable_items(int index);
  ::google::protobuf::RepeatedPtrField< ::request_proto::BindingQueryItem >*
      mutable_items();
  const ::request_proto::BindingQueryItem& items(int index) const;
  ::request_proto::BindingQueryItem* add_items();
  const ::google::protobuf::RepeatedPtrField< ::request_proto::BindingQueryItem >&
      items() const;

  // @@protoc_insertion_point(class_scope:request_proto.BindingQueryMessage)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::request_proto::BindingQueryItem > items_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_BindingQuery_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// BindingQueryItem

// string contractID = 1;
inline void BindingQueryItem::clear_contractid() {
  contractid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BindingQueryItem::contractid() const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryItem.contractID)
  return contractid_.GetNoArena();
}
inline void BindingQueryItem::set_contractid(const ::std::string& value) {
  
  contractid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:request_proto.BindingQueryItem.contractID)
}
#if LANG_CXX11
inline void BindingQueryItem::set_contractid(::std::string&& value) {
  
  contractid_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:request_proto.BindingQueryItem.contractID)
}
#endif
inline void BindingQueryItem::set_contractid(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  contractid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:request_proto.BindingQueryItem.contractID)
}
inline void BindingQueryItem::set_contractid(const char* value, size_t size) {
  
  contractid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:request_proto.BindingQueryItem.contractID)
}
inline ::std::string* BindingQueryItem::mutable_contractid() {
  
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryItem.contractID)
  return contractid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BindingQueryItem::release_contractid() {
  // @@protoc_insertion_point(field_release:request_proto.BindingQueryItem.contractID)
  
  return contractid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BindingQueryItem::set_allocated_contractid(::std::string* contractid) {
  if (contractid != nullptr) {
    
  } else {
    
  }
  contractid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), contractid);
  // @@protoc_insertion_point(field_set_allocated:request_proto.BindingQueryItem.contractID)
}

// string contractBinding = 2;
inline void BindingQueryItem::clear_contractbinding() {
  contractbinding_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& BindingQueryItem::contractbinding() const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryItem.contractBinding)
  return contractbinding_.GetNoArena();
}
inline void BindingQueryItem::set_contractbinding(const ::std::string& value) {
  
  contractbinding_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:request_proto.BindingQueryItem.contractBinding)
}
#if LANG_CXX11
inline void BindingQueryItem::set_contractbinding(::std::string&& value) {
  
  contractbinding_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:request_proto.BindingQueryItem.contractBinding)
}
#endif
inline void BindingQueryItem::set_contractbinding(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  contractbinding_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:request_proto.BindingQueryItem.contractBinding)
}
inline void BindingQueryItem::set_contractbinding(const char* value, size_t size) {
  
  contractbinding_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:request_proto.BindingQueryItem.contractBinding)
}
inline ::std::string* BindingQueryItem::mutable_contractbinding() {
  
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryItem.contractBinding)
  return contractbinding_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* BindingQueryItem::release_contractbinding() {
  // @@protoc_insertion_point(field_release:request_proto.BindingQueryItem.contractBinding)
  
  return contractbinding_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void BindingQueryItem::set_allocated_contractbinding(::std::string* contractbinding) {
  if (contractbinding != nullptr) {
    
  } else {
    
  }
  contractbinding_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), contractbinding);
  // @@protoc_insertion_point(field_set_allocated:request_proto.BindingQueryItem.contractBinding)
}

// -------------------------------------------------------------------

// BindingQueryMessage

// repeated .request_proto.BindingQueryItem items = 1;
inline int BindingQueryMessage::items_size() const {
  return items_.size();
}
inline void BindingQueryMessage::clear_items() {
  items_.Clear();
}
inline ::request_proto::BindingQueryItem* BindingQueryMessage::mutable_items(int index) {
  // @@protoc_insertion_point(field_mutable:request_proto.BindingQueryMessage.items)
  return items_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::request_proto::BindingQueryItem >*
BindingQueryMessage::mutable_items() {
  // @@protoc_insertion_point(field_mutable_list:request_proto.BindingQueryMessage.items)
  return &items_;
}
inline const ::request_proto::BindingQueryItem& BindingQueryMessage::items(int index) const {
  // @@protoc_insertion_point(field_get:request_proto.BindingQueryMessage.items)
  return items_.Get(index);
}
inline ::request_proto::BindingQueryItem* BindingQueryMessage::add_items() {
  // @@protoc_insertion_point(field_add:request_proto.BindingQueryMessage.items)
  return items_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::request_proto::BindingQueryItem >&
BindingQueryMessage::items() const {
  // @@protoc_insertion_point(field_list:request_proto.BindingQueryMessage.items)
  return items_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace request_proto

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_BindingQuery_2eproto