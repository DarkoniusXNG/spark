#ifndef __EQU8_PUBLIC_ERROR_HPP_DEF__
#define __EQU8_PUBLIC_ERROR_HPP_DEF__

#include <stdint.h>

typedef uint64_t equ8_err_t;

#define EQU8_ERR_NONE 0x00000000u

#define EQU8_GET_ERR_CODE(c)  ((uint32_t)(c & 0xFFFF0000))
#define EQU8_GET_ERR_LINE(c)  (c & 0xFFFF)
#define EQU8_GET_ERR_CLASS(c) (c & 0xF0000000)
#define EQU8_GET_ERR_EXTENDED(c) ((uint32_t)(c >> 32))

#define EQU8_SUCCESS(c) (EQU8_GET_ERR_CODE(c) == EQU8_ERR_NONE)

#define EQU8_OK EQU8_ERR_NONE

//
// Integration errors
//
#define EQU8_INTEGRATION_ERR(n) (EQU8_ERR_INTEGRATION_CLASS | (n << 16))
#define EQU8_ERR_INTEGRATION_CLASS 0x50000000u

#define EQU8_ERR_INTEGRATION_UNINITIALIZED EQU8_INTEGRATION_ERR(0)
#define EQU8_ERR_INTEGRATION_ALREADY_INITIALIZED EQU8_INTEGRATION_ERR(1)
#define EQU8_ERR_INTEGRATION_RECEIVE_DATA_EXCEEDS_LIMIT EQU8_INTEGRATION_ERR(2)

//
// Client Status codes
//
#define EQU8_STATUS_ERR(n) (EQU8_ERR_STATUS_CLASS | (n << 16))
#define EQU8_ERR_STATUS_CLASS 0x60000000u

#define EQU8_ERR_STATUS_AGENT_TERMINATED EQU8_STATUS_ERR(0)
#define EQU8_ERR_STATUS_CLIENT_AGENT_PROTOCOL_MISMATCH EQU8_STATUS_ERR(1)
#define EQU8_ERR_STATUS_SYSTEM_IN_TEST_SIGNING_MODE EQU8_STATUS_ERR(2)
#define EQU8_ERR_STATUS_DRIVER_REQUIRE_REBOOT EQU8_STATUS_ERR(3)
#define EQU8_ERR_STATUS_DRIVER_START_FAILURE EQU8_STATUS_ERR(4)
#define EQU8_ERR_STATUS_BAD_API EQU8_STATUS_ERR(5)
#define EQU8_ERR_STATUS_CORRUPT_CONFIGURATION EQU8_STATUS_ERR(6)
#define EQU8_ERR_STATUS_AC_CONNECTION_FAILURE EQU8_STATUS_ERR(7)

#endif // __EQU8_PUBLIC_ERROR_HPP_DEF__