//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-FPGA
//---------------------------------------------------------------------
#ifndef NIFPGA_GRPC_LIBRARY_WRAPPER_H
#define NIFPGA_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <NiFpga.h>

namespace nifpga_grpc {

class NiFpgaLibraryInterface {
 public:
  virtual ~NiFpgaLibraryInterface() {}

  virtual NiFpga_Status Initialize() = 0;
  virtual NiFpga_Status Finalize() = 0;
  virtual NiFpga_Status Open(const char* bitfile, const char* signature, const char* resource, uint32_t attribute, NiFpga_Session* session) = 0;
  virtual NiFpga_Status Close(NiFpga_Session session, uint32_t attribute) = 0;
  virtual NiFpga_Status Run(NiFpga_Session session, uint32_t attribute) = 0;
  virtual NiFpga_Status Reset(NiFpga_Session session) = 0;
  virtual NiFpga_Status Download(NiFpga_Session session) = 0;
  virtual NiFpga_Status ReadBool(NiFpga_Session session, uint32_t indicator, NiFpga_Bool* value) = 0;
  virtual NiFpga_Status ReadI8(NiFpga_Session session, uint32_t indicator, int8_t* value) = 0;
  virtual NiFpga_Status ReadU8(NiFpga_Session session, uint32_t indicator, uint8_t* value) = 0;
  virtual NiFpga_Status ReadI16(NiFpga_Session session, uint32_t indicator, int16_t* value) = 0;
  virtual NiFpga_Status ReadU16(NiFpga_Session session, uint32_t indicator, uint16_t* value) = 0;
  virtual NiFpga_Status ReadI32(NiFpga_Session session, uint32_t indicator, int32_t* value) = 0;
  virtual NiFpga_Status ReadU32(NiFpga_Session session, uint32_t indicator, uint32_t* value) = 0;
  virtual NiFpga_Status ReadI64(NiFpga_Session session, uint32_t indicator, int64_t* value) = 0;
  virtual NiFpga_Status ReadU64(NiFpga_Session session, uint32_t indicator, uint64_t* value) = 0;
  virtual NiFpga_Status WriteBool(NiFpga_Session session, uint32_t control, NiFpga_Bool value) = 0;
  virtual NiFpga_Status WriteI8(NiFpga_Session session, uint32_t control, int8_t value) = 0;
  virtual NiFpga_Status WriteU8(NiFpga_Session session, uint32_t control, uint8_t value) = 0;
  virtual NiFpga_Status WriteI16(NiFpga_Session session, uint32_t control, int16_t value) = 0;
  virtual NiFpga_Status WriteU16(NiFpga_Session session, uint32_t control, uint16_t value) = 0;
  virtual NiFpga_Status WriteI32(NiFpga_Session session, uint32_t control, int32_t value) = 0;
  virtual NiFpga_Status WriteU32(NiFpga_Session session, uint32_t control, uint32_t value) = 0;
  virtual NiFpga_Status WriteI64(NiFpga_Session session, uint32_t control, int64_t value) = 0;
  virtual NiFpga_Status WriteU64(NiFpga_Session session, uint32_t control, uint64_t value) = 0;
};

}  // namespace nifpga_grpc
#endif  // NIFPGA_GRPC_LIBRARY_WRAPPER_H
