/*
* 
* PoC that execute dot net assembly to pop a calc using COM 
* 
*/

#include "common.h"

unsigned char rawData[] = {
	0x4d,0x5a,0x90,0x00,0x03,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0xff,0xff,0x00,0x00,0xb8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x0e,0x1f,0xba,0x0e,0x00,0xb4,0x09,0xcd,0x21,0xb8,0x01,0x4c,0xcd,0x21,0x54,0x68,0x69,0x73,0x20,0x70,0x72,0x6f,0x67,0x72,0x61,0x6d,0x20,0x63,0x61,0x6e,0x6e,0x6f,0x74,0x20,0x62,0x65,0x20,0x72,0x75,0x6e,0x20,0x69,0x6e,0x20,0x44,0x4f,0x53,0x20,0x6d,0x6f,0x64,0x65,0x2e,0x0d,0x0d,0x0a,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x50,0x45,0x00,0x00,0x4c,0x01,0x03,0x00,0x5d,0xeb,0xc2,0xd6,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x00,0x22,0x00,0x0b,0x01,0x30,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0x27,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0x00,0x00,0x02,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x60,0x85,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x27,0x00,0x00,0x4f,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0xcc,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x0c,0x00,0x00,0x00,0x50,0x26,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x20,0x00,0x00,0x48,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2e,0x74,0x65,0x78,0x74,0x00,0x00,0x00,0x70,0x07,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x60,0x2e,0x72,0x73,0x72,0x63,0x00,0x00,0x00,0xcc,0x05,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x40,0x2e,0x72,0x65,0x6c,0x6f,0x63,0x00,0x00,0x0c,0x00,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4c,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x00,0x00,0x00,0x02,0x00,0x05,0x00,0x6c,0x20,0x00,0x00,0xe4,0x05,0x00,0x00,0x03,0x00,0x02,0x00,0x01,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x46,0x72,0x01,0x00,0x00,0x70,0x72,0x13,0x00,0x00,0x70,0x28,0x0f,0x00,0x00,0x0a,0x26,0x2a,0x1e,0x02,0x28,0x10,0x00,0x00,0x0a,0x2a,0x00,0x00,0x42,0x53,0x4a,0x42,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x76,0x34,0x2e,0x30,0x2e,0x33,0x30,0x33,0x31,0x39,0x00,0x00,0x00,0x00,0x05,0x00,0x6c,0x00,0x00,0x00,0xe0,0x01,0x00,0x00,0x23,0x7e,0x00,0x00,0x4c,0x02,0x00,0x00,0x58,0x02,0x00,0x00,0x23,0x53,0x74,0x72,0x69,0x6e,0x67,0x73,0x00,0x00,0x00,0x00,0xa4,0x04,0x00,0x00,0x18,0x00,0x00,0x00,0x23,0x55,0x53,0x00,0xbc,0x04,0x00,0x00,0x10,0x00,0x00,0x00,0x23,0x47,0x55,0x49,0x44,0x00,0x00,0x00,0xcc,0x04,0x00,0x00,0x18,0x01,0x00,0x00,0x23,0x42,0x6c,0x6f,0x62,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x01,0x47,0x15,0x00,0x00,0x09,0x00,0x00,0x00,0x00,0xfa,0x01,0x33,0x00,0x16,0x00,0x00,0x01,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x85,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0xfa,0x00,0x0e,0x02,0x06,0x00,0x67,0x01,0x0e,0x02,0x06,0x00,0x2e,0x00,0xdc,0x01,0x0f,0x00,0x2e,0x02,0x00,0x00,0x06,0x00,0x56,0x00,0xc4,0x01,0x06,0x00,0xdd,0x00,0xc4,0x01,0x06,0x00,0xbe,0x00,0xc4,0x01,0x06,0x00,0x4e,0x01,0xc4,0x01,0x06,0x00,0x1a,0x01,0xc4,0x01,0x06,0x00,0x33,0x01,0xc4,0x01,0x06,0x00,0x6d,0x00,0xc4,0x01,0x06,0x00,0x42,0x00,0xef,0x01,0x06,0x00,0x20,0x00,0xef,0x01,0x06,0x00,0xa1,0x00,0xc4,0x01,0x06,0x00,0x88,0x00,0x96,0x01,0x06,0x00,0x4a,0x02,0xb8,0x01,0x0a,0x00,0x42,0x02,0xdc,0x01,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x10,0x00,0xb0,0x01,0x13,0x00,0x41,0x00,0x01,0x00,0x01,0x00,0x50,0x20,0x00,0x00,0x00,0x00,0x91,0x00,0xbf,0x01,0x2a,0x00,0x01,0x00,0x62,0x20,0x00,0x00,0x00,0x00,0x86,0x18,0xd6,0x01,0x06,0x00,0x02,0x00,0x00,0x00,0x01,0x00,0x3d,0x02,0x09,0x00,0xd6,0x01,0x01,0x00,0x11,0x00,0xd6,0x01,0x06,0x00,0x19,0x00,0xd6,0x01,0x0a,0x00,0x29,0x00,0xd6,0x01,0x10,0x00,0x31,0x00,0xd6,0x01,0x10,0x00,0x39,0x00,0xd6,0x01,0x10,0x00,0x41,0x00,0xd6,0x01,0x10,0x00,0x49,0x00,0xd6,0x01,0x10,0x00,0x51,0x00,0xd6,0x01,0x10,0x00,0x59,0x00,0xd6,0x01,0x10,0x00,0x61,0x00,0xd6,0x01,0x15,0x00,0x69,0x00,0xd6,0x01,0x10,0x00,0x71,0x00,0xd6,0x01,0x10,0x00,0x79,0x00,0xd6,0x01,0x10,0x00,0x89,0x00,0x51,0x02,0x1a,0x00,0x81,0x00,0xd6,0x01,0x06,0x00,0x2e,0x00,0x0b,0x00,0x30,0x00,0x2e,0x00,0x13,0x00,0x39,0x00,0x2e,0x00,0x1b,0x00,0x58,0x00,0x2e,0x00,0x23,0x00,0x61,0x00,0x2e,0x00,0x2b,0x00,0x73,0x00,0x2e,0x00,0x33,0x00,0x73,0x00,0x2e,0x00,0x3b,0x00,0x73,0x00,0x2e,0x00,0x43,0x00,0x61,0x00,0x2e,0x00,0x4b,0x00,0x79,0x00,0x2e,0x00,0x53,0x00,0x73,0x00,0x2e,0x00,0x5b,0x00,0x73,0x00,0x2e,0x00,0x63,0x00,0x91,0x00,0x2e,0x00,0x6b,0x00,0xbb,0x00,0x2e,0x00,0x73,0x00,0xc8,0x00,0x04,0x80,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x13,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x00,0x0a,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x00,0xb8,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x4d,0x6f,0x64,0x75,0x6c,0x65,0x3e,0x00,0x6d,0x73,0x63,0x6f,0x72,0x6c,0x69,0x62,0x00,0x44,0x6f,0x74,0x4e,0x65,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x00,0x47,0x75,0x69,0x64,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x44,0x65,0x62,0x75,0x67,0x67,0x61,0x62,0x6c,0x65,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x43,0x6f,0x6d,0x56,0x69,0x73,0x69,0x62,0x6c,0x65,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x54,0x69,0x74,0x6c,0x65,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x54,0x72,0x61,0x64,0x65,0x6d,0x61,0x72,0x6b,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x54,0x61,0x72,0x67,0x65,0x74,0x46,0x72,0x61,0x6d,0x65,0x77,0x6f,0x72,0x6b,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x46,0x69,0x6c,0x65,0x56,0x65,0x72,0x73,0x69,0x6f,0x6e,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x43,0x6f,0x6e,0x66,0x69,0x67,0x75,0x72,0x61,0x74,0x69,0x6f,0x6e,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x44,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,0x6f,0x6e,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x43,0x6f,0x6d,0x70,0x69,0x6c,0x61,0x74,0x69,0x6f,0x6e,0x52,0x65,0x6c,0x61,0x78,0x61,0x74,0x69,0x6f,0x6e,0x73,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x50,0x72,0x6f,0x64,0x75,0x63,0x74,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x43,0x6f,0x70,0x79,0x72,0x69,0x67,0x68,0x74,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x41,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x43,0x6f,0x6d,0x70,0x61,0x6e,0x79,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x52,0x75,0x6e,0x74,0x69,0x6d,0x65,0x43,0x6f,0x6d,0x70,0x61,0x74,0x69,0x62,0x69,0x6c,0x69,0x74,0x79,0x41,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x00,0x44,0x6f,0x74,0x4e,0x65,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x2e,0x65,0x78,0x65,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x2e,0x52,0x75,0x6e,0x74,0x69,0x6d,0x65,0x2e,0x56,0x65,0x72,0x73,0x69,0x6f,0x6e,0x69,0x6e,0x67,0x00,0x50,0x72,0x6f,0x67,0x72,0x61,0x6d,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x00,0x4d,0x61,0x69,0x6e,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x2e,0x52,0x65,0x66,0x6c,0x65,0x63,0x74,0x69,0x6f,0x6e,0x00,0x2e,0x63,0x74,0x6f,0x72,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x2e,0x44,0x69,0x61,0x67,0x6e,0x6f,0x73,0x74,0x69,0x63,0x73,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x2e,0x52,0x75,0x6e,0x74,0x69,0x6d,0x65,0x2e,0x49,0x6e,0x74,0x65,0x72,0x6f,0x70,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x00,0x53,0x79,0x73,0x74,0x65,0x6d,0x2e,0x52,0x75,0x6e,0x74,0x69,0x6d,0x65,0x2e,0x43,0x6f,0x6d,0x70,0x69,0x6c,0x65,0x72,0x53,0x65,0x72,0x76,0x69,0x63,0x65,0x73,0x00,0x44,0x65,0x62,0x75,0x67,0x67,0x69,0x6e,0x67,0x4d,0x6f,0x64,0x65,0x73,0x00,0x61,0x72,0x67,0x73,0x00,0x50,0x72,0x6f,0x63,0x65,0x73,0x73,0x00,0x4f,0x62,0x6a,0x65,0x63,0x74,0x00,0x53,0x74,0x61,0x72,0x74,0x00,0x00,0x00,0x11,0x63,0x00,0x61,0x00,0x6c,0x00,0x63,0x00,0x2e,0x00,0x65,0x00,0x78,0x00,0x65,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x13,0x54,0xca,0xeb,0xfe,0x63,0x9b,0x45,0x82,0xb5,0x8c,0xb6,0xa7,0xe0,0xf1,0x50,0x00,0x04,0x20,0x01,0x01,0x08,0x03,0x20,0x00,0x01,0x05,0x20,0x01,0x01,0x11,0x11,0x04,0x20,0x01,0x01,0x0e,0x04,0x20,0x01,0x01,0x02,0x06,0x00,0x02,0x12,0x45,0x0e,0x0e,0x08,0xb7,0x7a,0x5c,0x56,0x19,0x34,0xe0,0x89,0x05,0x00,0x01,0x01,0x1d,0x0e,0x08,0x01,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x1e,0x01,0x00,0x01,0x00,0x54,0x02,0x16,0x57,0x72,0x61,0x70,0x4e,0x6f,0x6e,0x45,0x78,0x63,0x65,0x70,0x74,0x69,0x6f,0x6e,0x54,0x68,0x72,0x6f,0x77,0x73,0x01,0x08,0x01,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x11,0x01,0x00,0x0c,0x44,0x6f,0x74,0x4e,0x65,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x00,0x00,0x05,0x01,0x00,0x00,0x00,0x00,0x17,0x01,0x00,0x12,0x43,0x6f,0x70,0x79,0x72,0x69,0x67,0x68,0x74,0x20,0xc2,0xa9,0x20,0x20,0x32,0x30,0x32,0x33,0x00,0x00,0x29,0x01,0x00,0x24,0x62,0x36,0x62,0x37,0x39,0x66,0x33,0x63,0x2d,0x33,0x66,0x33,0x63,0x2d,0x34,0x64,0x65,0x61,0x2d,0x39,0x65,0x61,0x34,0x2d,0x61,0x36,0x35,0x37,0x63,0x62,0x63,0x66,0x65,0x65,0x39,0x31,0x00,0x00,0x0c,0x01,0x00,0x07,0x31,0x2e,0x30,0x2e,0x30,0x2e,0x30,0x00,0x00,0x4d,0x01,0x00,0x1c,0x2e,0x4e,0x45,0x54,0x46,0x72,0x61,0x6d,0x65,0x77,0x6f,0x72,0x6b,0x2c,0x56,0x65,0x72,0x73,0x69,0x6f,0x6e,0x3d,0x76,0x34,0x2e,0x37,0x2e,0x32,0x01,0x00,0x54,0x0e,0x14,0x46,0x72,0x61,0x6d,0x65,0x77,0x6f,0x72,0x6b,0x44,0x69,0x73,0x70,0x6c,0x61,0x79,0x4e,0x61,0x6d,0x65,0x14,0x2e,0x4e,0x45,0x54,0x20,0x46,0x72,0x61,0x6d,0x65,0x77,0x6f,0x72,0x6b,0x20,0x34,0x2e,0x37,0x2e,0x32,0x00,0x00,0x00,0x00,0x00,0x00,0xad,0x60,0x30,0xff,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x90,0x00,0x00,0x00,0x88,0x26,0x00,0x00,0x88,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x52,0x53,0x44,0x53,0xc7,0x4c,0x6d,0x1a,0xd6,0xbd,0xdc,0x47,0xab,0x63,0x2c,0x3f,0x09,0x0b,0xc2,0x02,0x01,0x00,0x00,0x00,0x43,0x3a,0x5c,0x55,0x73,0x65,0x72,0x73,0x5c,0x6f,0x70,0x72,0x6f,0x70,0x5c,0x73,0x6f,0x75,0x72,0x63,0x65,0x5c,0x72,0x65,0x70,0x6f,0x73,0x5c,0x52,0x65,0x64,0x41,0x6c,0x65,0x72,0x74,0x5c,0x57,0x69,0x6e,0x64,0x6f,0x77,0x73,0x5c,0x49,0x6e,0x74,0x65,0x72,0x6e,0x61,0x6c,0x73,0x5c,0x4d,0x61,0x6c,0x44,0x65,0x76,0x5c,0x54,0x68,0x65,0x57,0x68,0x6f,0x6c,0x65,0x53,0x68,0x65,0x62,0x61,0x6e,0x67,0x5c,0x44,0x6f,0x74,0x4e,0x65,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x5c,0x6f,0x62,0x6a,0x5c,0x52,0x65,0x6c,0x65,0x61,0x73,0x65,0x5c,0x44,0x6f,0x74,0x4e,0x65,0x74,0x53,0x61,0x6d,0x70,0x6c,0x65,0x2e,0x70,0x64,0x62,0x00,0x40,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5a,0x27,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4c,0x27,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x5f,0x43,0x6f,0x72,0x45,0x78,0x65,0x4d,0x61,0x69,0x6e,0x00,0x6d,0x73,0x63,0x6f,0x72,0x65,0x65,0x2e,0x64,0x6c,0x6c,0x00,0x00,0x00,0x00,0x00,0xff,0x25,0x00,0x20,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x10,0x00,0x00,0x00,0x20,0x00,0x00,0x80,0x18,0x00,0x00,0x00,0x50,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x38,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x68,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0xcc,0x03,0x00,0x00,0x90,0x40,0x00,0x00,0x3c,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x03,0x34,0x00,0x00,0x00,0x56,0x00,0x53,0x00,0x5f,0x00,0x56,0x00,0x45,0x00,0x52,0x00,0x53,0x00,0x49,0x00,0x4f,0x00,0x4e,0x00,0x5f,0x00,0x49,0x00,0x4e,0x00,0x46,0x00,0x4f,0x00,0x00,0x00,0x00,0x00,0xbd,0x04,0xef,0xfe,0x00,0x00,0x01,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x00,0x00,0x01,0x00,0x56,0x00,0x61,0x00,0x72,0x00,0x46,0x00,0x69,0x00,0x6c,0x00,0x65,0x00,0x49,0x00,0x6e,0x00,0x66,0x00,0x6f,0x00,0x00,0x00,0x00,0x00,0x24,0x00,0x04,0x00,0x00,0x00,0x54,0x00,0x72,0x00,0x61,0x00,0x6e,0x00,0x73,0x00,0x6c,0x00,0x61,0x00,0x74,0x00,0x69,0x00,0x6f,0x00,0x6e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xb0,0x04,0x9c,0x02,0x00,0x00,0x01,0x00,0x53,0x00,0x74,0x00,0x72,0x00,0x69,0x00,0x6e,0x00,0x67,0x00,0x46,0x00,0x69,0x00,0x6c,0x00,0x65,0x00,0x49,0x00,0x6e,0x00,0x66,0x00,0x6f,0x00,0x00,0x00,0x78,0x02,0x00,0x00,0x01,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x30,0x00,0x34,0x00,0x62,0x00,0x30,0x00,0x00,0x00,0x1a,0x00,0x01,0x00,0x01,0x00,0x43,0x00,0x6f,0x00,0x6d,0x00,0x6d,0x00,0x65,0x00,0x6e,0x00,0x74,0x00,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x22,0x00,0x01,0x00,0x01,0x00,0x43,0x00,0x6f,0x00,0x6d,0x00,0x70,0x00,0x61,0x00,0x6e,0x00,0x79,0x00,0x4e,0x00,0x61,0x00,0x6d,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x0d,0x00,0x01,0x00,0x46,0x00,0x69,0x00,0x6c,0x00,0x65,0x00,0x44,0x00,0x65,0x00,0x73,0x00,0x63,0x00,0x72,0x00,0x69,0x00,0x70,0x00,0x74,0x00,0x69,0x00,0x6f,0x00,0x6e,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x6f,0x00,0x74,0x00,0x4e,0x00,0x65,0x00,0x74,0x00,0x53,0x00,0x61,0x00,0x6d,0x00,0x70,0x00,0x6c,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x08,0x00,0x01,0x00,0x46,0x00,0x69,0x00,0x6c,0x00,0x65,0x00,0x56,0x00,0x65,0x00,0x72,0x00,0x73,0x00,0x69,0x00,0x6f,0x00,0x6e,0x00,0x00,0x00,0x00,0x00,0x31,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x00,0x00,0x42,0x00,0x11,0x00,0x01,0x00,0x49,0x00,0x6e,0x00,0x74,0x00,0x65,0x00,0x72,0x00,0x6e,0x00,0x61,0x00,0x6c,0x00,0x4e,0x00,0x61,0x00,0x6d,0x00,0x65,0x00,0x00,0x00,0x44,0x00,0x6f,0x00,0x74,0x00,0x4e,0x00,0x65,0x00,0x74,0x00,0x53,0x00,0x61,0x00,0x6d,0x00,0x70,0x00,0x6c,0x00,0x65,0x00,0x2e,0x00,0x65,0x00,0x78,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x48,0x00,0x12,0x00,0x01,0x00,0x4c,0x00,0x65,0x00,0x67,0x00,0x61,0x00,0x6c,0x00,0x43,0x00,0x6f,0x00,0x70,0x00,0x79,0x00,0x72,0x00,0x69,0x00,0x67,0x00,0x68,0x00,0x74,0x00,0x00,0x00,0x43,0x00,0x6f,0x00,0x70,0x00,0x79,0x00,0x72,0x00,0x69,0x00,0x67,0x00,0x68,0x00,0x74,0x00,0x20,0x00,0xa9,0x00,0x20,0x00,0x20,0x00,0x32,0x00,0x30,0x00,0x32,0x00,0x33,0x00,0x00,0x00,0x2a,0x00,0x01,0x00,0x01,0x00,0x4c,0x00,0x65,0x00,0x67,0x00,0x61,0x00,0x6c,0x00,0x54,0x00,0x72,0x00,0x61,0x00,0x64,0x00,0x65,0x00,0x6d,0x00,0x61,0x00,0x72,0x00,0x6b,0x00,0x73,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4a,0x00,0x11,0x00,0x01,0x00,0x4f,0x00,0x72,0x00,0x69,0x00,0x67,0x00,0x69,0x00,0x6e,0x00,0x61,0x00,0x6c,0x00,0x46,0x00,0x69,0x00,0x6c,0x00,0x65,0x00,0x6e,0x00,0x61,0x00,0x6d,0x00,0x65,0x00,0x00,0x00,0x44,0x00,0x6f,0x00,0x74,0x00,0x4e,0x00,0x65,0x00,0x74,0x00,0x53,0x00,0x61,0x00,0x6d,0x00,0x70,0x00,0x6c,0x00,0x65,0x00,0x2e,0x00,0x65,0x00,0x78,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x3a,0x00,0x0d,0x00,0x01,0x00,0x50,0x00,0x72,0x00,0x6f,0x00,0x64,0x00,0x75,0x00,0x63,0x00,0x74,0x00,0x4e,0x00,0x61,0x00,0x6d,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x44,0x00,0x6f,0x00,0x74,0x00,0x4e,0x00,0x65,0x00,0x74,0x00,0x53,0x00,0x61,0x00,0x6d,0x00,0x70,0x00,0x6c,0x00,0x65,0x00,0x00,0x00,0x00,0x00,0x34,0x00,0x08,0x00,0x01,0x00,0x50,0x00,0x72,0x00,0x6f,0x00,0x64,0x00,0x75,0x00,0x63,0x00,0x74,0x00,0x56,0x00,0x65,0x00,0x72,0x00,0x73,0x00,0x69,0x00,0x6f,0x00,0x6e,0x00,0x00,0x00,0x31,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x00,0x00,0x38,0x00,0x08,0x00,0x01,0x00,0x41,0x00,0x73,0x00,0x73,0x00,0x65,0x00,0x6d,0x00,0x62,0x00,0x6c,0x00,0x79,0x00,0x20,0x00,0x56,0x00,0x65,0x00,0x72,0x00,0x73,0x00,0x69,0x00,0x6f,0x00,0x6e,0x00,0x00,0x00,0x31,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x2e,0x00,0x30,0x00,0x00,0x00,0xdc,0x43,0x00,0x00,0xea,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xef,0xbb,0xbf,0x3c,0x3f,0x78,0x6d,0x6c,0x20,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x3d,0x22,0x31,0x2e,0x30,0x22,0x20,0x65,0x6e,0x63,0x6f,0x64,0x69,0x6e,0x67,0x3d,0x22,0x55,0x54,0x46,0x2d,0x38,0x22,0x20,0x73,0x74,0x61,0x6e,0x64,0x61,0x6c,0x6f,0x6e,0x65,0x3d,0x22,0x79,0x65,0x73,0x22,0x3f,0x3e,0x0d,0x0a,0x0d,0x0a,0x3c,0x61,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x22,0x75,0x72,0x6e,0x3a,0x73,0x63,0x68,0x65,0x6d,0x61,0x73,0x2d,0x6d,0x69,0x63,0x72,0x6f,0x73,0x6f,0x66,0x74,0x2d,0x63,0x6f,0x6d,0x3a,0x61,0x73,0x6d,0x2e,0x76,0x31,0x22,0x20,0x6d,0x61,0x6e,0x69,0x66,0x65,0x73,0x74,0x56,0x65,0x72,0x73,0x69,0x6f,0x6e,0x3d,0x22,0x31,0x2e,0x30,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x61,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x49,0x64,0x65,0x6e,0x74,0x69,0x74,0x79,0x20,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x3d,0x22,0x31,0x2e,0x30,0x2e,0x30,0x2e,0x30,0x22,0x20,0x6e,0x61,0x6d,0x65,0x3d,0x22,0x4d,0x79,0x41,0x70,0x70,0x6c,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,0x2e,0x61,0x70,0x70,0x22,0x2f,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x74,0x72,0x75,0x73,0x74,0x49,0x6e,0x66,0x6f,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x22,0x75,0x72,0x6e,0x3a,0x73,0x63,0x68,0x65,0x6d,0x61,0x73,0x2d,0x6d,0x69,0x63,0x72,0x6f,0x73,0x6f,0x66,0x74,0x2d,0x63,0x6f,0x6d,0x3a,0x61,0x73,0x6d,0x2e,0x76,0x32,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x73,0x65,0x63,0x75,0x72,0x69,0x74,0x79,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x65,0x64,0x50,0x72,0x69,0x76,0x69,0x6c,0x65,0x67,0x65,0x73,0x20,0x78,0x6d,0x6c,0x6e,0x73,0x3d,0x22,0x75,0x72,0x6e,0x3a,0x73,0x63,0x68,0x65,0x6d,0x61,0x73,0x2d,0x6d,0x69,0x63,0x72,0x6f,0x73,0x6f,0x66,0x74,0x2d,0x63,0x6f,0x6d,0x3a,0x61,0x73,0x6d,0x2e,0x76,0x33,0x22,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x65,0x64,0x45,0x78,0x65,0x63,0x75,0x74,0x69,0x6f,0x6e,0x4c,0x65,0x76,0x65,0x6c,0x20,0x6c,0x65,0x76,0x65,0x6c,0x3d,0x22,0x61,0x73,0x49,0x6e,0x76,0x6f,0x6b,0x65,0x72,0x22,0x20,0x75,0x69,0x41,0x63,0x63,0x65,0x73,0x73,0x3d,0x22,0x66,0x61,0x6c,0x73,0x65,0x22,0x2f,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x20,0x20,0x3c,0x2f,0x72,0x65,0x71,0x75,0x65,0x73,0x74,0x65,0x64,0x50,0x72,0x69,0x76,0x69,0x6c,0x65,0x67,0x65,0x73,0x3e,0x0d,0x0a,0x20,0x20,0x20,0x20,0x3c,0x2f,0x73,0x65,0x63,0x75,0x72,0x69,0x74,0x79,0x3e,0x0d,0x0a,0x20,0x20,0x3c,0x2f,0x74,0x72,0x75,0x73,0x74,0x49,0x6e,0x66,0x6f,0x3e,0x0d,0x0a,0x3c,0x2f,0x61,0x73,0x73,0x65,0x6d,0x62,0x6c,0x79,0x3e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x0c,0x00,0x00,0x00,0x6c,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

//\
https://github.com/med0x2e/ExecuteAssembly/blob/main/ExecuteAssembly/x64(nt-syscalls)/ExecuteAssembly/src/HostCLR.cpp
//
// set parameters for the assembly according to parameter count
//
SAFEARRAY* __set_params(LPSTR* arguments, SIZE_T argc)
{

	VARIANT args;
	args.vt = VT_ARRAY | VT_BSTR;
	SAFEARRAYBOUND argsBound[1];
	argsBound[0].lLbound = 0;
	SIZE_T argsLength = arguments != NULL ? argc : 0;
	argsBound[0].cElements = argsLength;
	args.parray = SafeArrayCreate(VT_BSTR, 1, argsBound);
	LONG idx[1] = { 0x0 };
	for (USHORT i = 0; i < argsLength; i++)
	{
		idx[0] = i;
		SafeArrayPutElement(args.parray, idx, SysAllocString(_bstr_t(arguments[i]).Detach()));
	}

	SAFEARRAY* params = NULL;
	SAFEARRAYBOUND paramsBound[1];
	paramsBound[0].lLbound = 0;
	paramsBound[0].cElements = 1;
	params = SafeArrayCreate(VT_VARIANT, 1, paramsBound);
	idx[0] = 0;
	SafeArrayPutElement(params, idx, &args);

	ZeroMemory(&args, sizeof(VARIANT));

	return params;
}

int main(int argc, char** argv)
{
	ICLRMetaHost* pMetaHost = NULL;
	ICLRRuntimeInfo* pRuntimeInfo = NULL;
	ICorRuntimeHost* pRuntimeHost = NULL;
	IUnknownPtr pAppDomainThunk = NULL;
	SAFEARRAY* params = NULL;
	_AssemblyPtr pAssembly = NULL;
	_AppDomainPtr pDefaultAppDomain = NULL;
	_MethodInfoPtr pMethodInfo = NULL;
	VARIANT ret = { 0x0 };
	VARIANT obj = { 0x0 };
	HRESULT hr = 0x0;
	DWORD dwRawDataSize = sizeof(rawData);

	printf("[*]Size of raw data %ld\n", dwRawDataSize);
	printf("%-45s", "[*]CLRCreateInstance ... ");

	hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (VOID**)&pMetaHost);
	if (FAILED(hr))
	{
		printf("[-]CLRCreateInstance failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done!\n");
	printf("%-45s", "[+]GetRuntime ... ");

	hr = pMetaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (VOID**)&pRuntimeInfo);
	if (FAILED(hr))
	{
		printf("[-]GetRuntime failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]Checking IsLoadable ... ");

	BOOL bLoadable;

	hr = pRuntimeInfo->IsLoadable(&bLoadable);
	if (FAILED(hr) || !bLoadable)
	{
		printf("[-]Check IsLoadable failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]GetInterface ... ");

	hr = pRuntimeInfo->GetInterface(CLSID_CorRuntimeHost, IID_ICorRuntimeHost, (VOID**)&pRuntimeHost);
	if (FAILED(hr))
	{
		printf("[-]GetInterface failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]Start RuntimeHost ... ");

	/* Start the CLR */

	hr = pRuntimeHost->Start();
	if (FAILED(hr))
	{
		printf("[-]Start RuntimeHost failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]GetDefaultDomain ... ");

	hr = pRuntimeHost->GetDefaultDomain(&pAppDomainThunk);
	if (FAILED(hr))
	{
		printf("[-]GetDefaultDomain failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]QueryInterface ... ");

	/* Equivalent of System.AppDomain.CurrentDomain in C# */

	hr = pAppDomainThunk->QueryInterface(__uuidof(_AppDomain), (PVOID*)&pDefaultAppDomain);
	if (FAILED(hr))
	{
		printf("[-]QueryInterface failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]Prepare assembly data ... ");

	SAFEARRAYBOUND bound[1];
	bound[0].cElements = dwRawDataSize;
	bound[0].lLbound = 0;

	SAFEARRAY* pSafeArray = SafeArrayCreate(VT_UI1, 1, bound);
	SafeArrayLock(pSafeArray);
	memcpy(pSafeArray->pvData, rawData, dwRawDataSize);
	SafeArrayUnlock(pSafeArray);

	printf("[+]Done! \n");
	printf("%-45s", "[*]Load assembly with Load_3 ... ");

	hr = pDefaultAppDomain->Load_3(pSafeArray, &pAssembly);
	if (FAILED(hr))
	{
		printf("[-]Load_3 failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]Get assembly entry point ... ");

	hr = pAssembly->get_EntryPoint(&pMethodInfo);
	if (FAILED(hr))
	{
		printf("[-]get_EntryPoint failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");
	printf("%-45s", "[*]Prepare arguments ... ");

	params = __set_params(NULL, 0);

	ZeroMemory(&ret, sizeof(VARIANT));
	ZeroMemory(&obj, sizeof(VARIANT));
	obj.vt = VT_NULL;

	printf("[+]Done! \n");
	printf("%-45s", "[*]Invoking the assembly with Invoke_3 ... ");

	hr = pMethodInfo->Invoke_3(obj, params, &ret);
	if (FAILED(hr))
	{
		printf("[-]Invoke_3 failed with status: 0x%.8X\n", hr);
		goto _exit;
	}

	printf("[+]Done! \n");

_exit:
	if (pMetaHost) pMetaHost->Release();
	if (pRuntimeHost) pRuntimeHost->Stop();
	if (pRuntimeHost) pRuntimeHost->Release();
	if (params)
	{
		SafeArrayDestroy(params);
		params = NULL;
	}

	return 0;
}

