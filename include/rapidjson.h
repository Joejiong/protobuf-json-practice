// Copyright (c) 2015 baidu-rpc authors.
// Author: Zhangyi Chen (chenzhangyi01@baidu.com)
// Date: 2015/03/17 15:34:52

#ifndef  PROTOBUF_JSON_RAPIDJSON_H
#define  PROTOBUF_JSON_RAPIDJSON_H


#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)

#pragma GCC diagnostic push

#pragma GCC diagnostic ignored "-Wunused-local-typedefs"

#endif

// Try to detect rapidjson
// If rapidjson support baidu internal version 1.0, 
// it will define the BAIDU_RAPIDJSON_USE_VERSION_1_0 macro
#define BAIDU_RAPIDJSON_DETECT_VERSION 1
#include "rapidjson/rapidjson.h"
#undef BAIDU_RAPIDJSON_DETECT_VERSION

#ifdef BAIDU_RAPIDJSON_USE_VERSION_1_0

#include "rapidjson_1.0/allocators.h"
#include "rapidjson_1.0/document.h"
#include "rapidjson_1.0/encodedstream.h"
#include "rapidjson_1.0/encodings.h"
#include "rapidjson_1.0/filereadstream.h"
#include "rapidjson_1.0/filewritestream.h"
#include "rapidjson_1.0/prettywriter.h"
#include "rapidjson_1.0/reader.h"
#include "rapidjson_1.0/stringbuffer.h"
#include "rapidjson_1.0/writer.h"
#include "rapidjson_1.0/optimized_writer.h"

#else

#include "rapidjson/allocators.h"
#include "rapidjson/document.h"
#include "rapidjson/encodedstream.h"
#include "rapidjson/encodings.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include "rapidjson/prettywriter.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

#ifdef BAIDU_RAPIDJSON_HAS_FILE_STREAM
#include "rapidjson/filestream.h"
#endif // BAIDU_RAPIDJSON_HAS_FILE_STREAM

#ifdef BAIDU_RAPIDJSON_HAS_OPTIMIZED_WRITER
#include "rapidjson/optimized_writer.h"
#endif // BAIDU_RAPIDJSON_HAS_OPTIMIZED_WRITER

#endif // BAIDU_RAPIDJSON_USE_VERSION_1_0

#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 8)
#pragma GCC diagnostic pop
#endif

#endif  //PROTOBUF_JSON_RAPIDJSON_H
