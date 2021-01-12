#COMAKE2 edit-mode: -*- Makefile -*-
####################64Bit Mode####################
ifeq ($(shell uname -m),x86_64)
CC=gcc
CXX=g++
CXXFLAGS=
CFLAGS=
CPPFLAGS=-D_GNU_SOURCE \
  -D__STDC_LIMIT_MACROS \
  -g \
  -O2 \
  -pipe \
  -W \
  -Wall \
  -fPIC \
  -fno-omit-frame-pointer \
  -include \
  ../config.h
INCPATH=-I../src \
  -I../include
DEP_INCPATH=-I../../../../lib2-64/ullib \
  -I../../../../lib2-64/ullib/include \
  -I../../../../lib2-64/ullib/output \
  -I../../../../lib2-64/ullib/output/include \
  -I../../../../baidu/base/common \
  -I../../../../baidu/base/common/include \
  -I../../../../baidu/base/common/output \
  -I../../../../baidu/base/common/output/include \
  -I../../../../baidu/base/iobuf \
  -I../../../../baidu/base/iobuf/include \
  -I../../../../baidu/base/iobuf/output \
  -I../../../../baidu/base/iobuf/output/include \
  -I../../../../quality/autotest/reportlib/cpp \
  -I../../../../quality/autotest/reportlib/cpp/include \
  -I../../../../quality/autotest/reportlib/cpp/output \
  -I../../../../quality/autotest/reportlib/cpp/output/include \
  -I../../../../third-64/boost \
  -I../../../../third-64/boost/include \
  -I../../../../third-64/boost/output \
  -I../../../../third-64/boost/output/include \
  -I../../../../third-64/gflags \
  -I../../../../third-64/gflags/include \
  -I../../../../third-64/gflags/output \
  -I../../../../third-64/gflags/output/include \
  -I../../../../third-64/libevent \
  -I../../../../third-64/libevent/include \
  -I../../../../third-64/libevent/output \
  -I../../../../third-64/libevent/output/include \
  -I../../../../third-64/protobuf \
  -I../../../../third-64/protobuf/include \
  -I../../../../third-64/protobuf/output \
  -I../../../../third-64/protobuf/output/include \
  -I../../../../thirdsrc/gtest \
  -I../../../../thirdsrc/gtest/include \
  -I../../../../thirdsrc/gtest/output \
  -I../../../../thirdsrc/gtest/output/include \
  -I../../../../thirdsrc/tcmalloc \
  -I../../../../thirdsrc/tcmalloc/include \
  -I../../../../thirdsrc/tcmalloc/output \
  -I../../../../thirdsrc/tcmalloc/output/include

#============ CCP vars ============
CCHECK=@ccheck.py
CCHECK_FLAGS=
PCLINT=@pclint
PCLINT_FLAGS=
CCP=@ccp.py
CCP_FLAGS=


#COMAKE UUID
COMAKE_MD5=432c15a2fba9ce66fe5217405bf33fb4  COMAKE


.PHONY:all
all:comake2_makefile_check test_protobuf_json test_repeated_field 
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mall[0m']"
	@echo "make all done"

.PHONY:comake2_makefile_check
comake2_makefile_check:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mcomake2_makefile_check[0m']"
	#in case of error, update 'Makefile' by 'comake2'
	@echo "$(COMAKE_MD5)">comake2.md5
	@md5sum -c --status comake2.md5
	@rm -f comake2.md5

.PHONY:ccpclean
ccpclean:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mccpclean[0m']"
	@echo "make ccpclean done"

.PHONY:clean
clean:ccpclean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mclean[0m']"
	rm -rf test_protobuf_json
	rm -rf ./output/bin/test_protobuf_json
	rm -rf test_repeated_field
	rm -rf ./output/bin/test_repeated_field
	rm -rf test_protobuf_json_test_protobuf_json.o
	rm -rf ./addressbook1.pb.cc
	rm -rf ./addressbook1.pb.h
	rm -rf ./test_protobuf_json_addressbook1.pb.o
	rm -rf ./addressbook.pb.cc
	rm -rf ./addressbook.pb.h
	rm -rf ./test_protobuf_json_addressbook.pb.o
	rm -rf ./message.pb.cc
	rm -rf ./message.pb.h
	rm -rf ./test_protobuf_json_message.pb.o
	rm -rf ./addressbook_encode_decode.pb.cc
	rm -rf ./addressbook_encode_decode.pb.h
	rm -rf ./test_protobuf_json_addressbook_encode_decode.pb.o
	rm -rf ./addressbook_map.pb.cc
	rm -rf ./addressbook_map.pb.h
	rm -rf ./test_protobuf_json_addressbook_map.pb.o
	rm -rf test_repeated_field_test_repeated_field.o
	rm -rf ./repeated.pb.cc
	rm -rf ./repeated.pb.h
	rm -rf ./test_repeated_field_repeated.pb.o

.PHONY:dist
dist:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdist[0m']"
	tar czvf output.tar.gz output
	@echo "make dist done"

.PHONY:distclean
distclean:clean
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mdistclean[0m']"
	rm -f output.tar.gz
	@echo "make distclean done"

.PHONY:love
love:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mlove[0m']"
	@echo "make love done"

test_protobuf_json:test_protobuf_json_test_protobuf_json.o \
  test_protobuf_json_addressbook1.pb.o \
  test_protobuf_json_addressbook.pb.o \
  test_protobuf_json_message.pb.o \
  test_protobuf_json_addressbook_encode_decode.pb.o \
  test_protobuf_json_addressbook_map.pb.o \
  ../libjson-pb.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_protobuf_json[0m']"
	$(CXX) test_protobuf_json_test_protobuf_json.o \
  test_protobuf_json_addressbook1.pb.o \
  test_protobuf_json_addressbook.pb.o \
  test_protobuf_json_message.pb.o \
  test_protobuf_json_addressbook_encode_decode.pb.o \
  test_protobuf_json_addressbook_map.pb.o -Xlinker "-(" ../libjson-pb.a ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../baidu/base/common/libbase.a \
  ../../../../baidu/base/iobuf/libiobuf.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/gflags/lib/libgflags.a \
  ../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../third-64/libevent/lib/libevent.a \
  ../../../../third-64/libevent/lib/libevent_core.a \
  ../../../../third-64/libevent/lib/libevent_extra.a \
  ../../../../third-64/libevent/lib/libevent_openssl.a \
  ../../../../third-64/libevent/lib/libevent_pthreads.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a \
  ../../../../thirdsrc/gtest/output/lib/libgmock.a \
  ../../../../thirdsrc/gtest/output/lib/libgmock_main.a \
  ../../../../thirdsrc/gtest/output/lib/libgtest.a \
  ../../../../thirdsrc/gtest/output/lib/libgtest_main.a \
  ../../../../thirdsrc/tcmalloc/output/lib/libprofiler.a -lpthread \
  -lcrypto \
  -lrt \
  -lssl \
  -ldl -Xlinker "-)" -o test_protobuf_json
	mkdir -p ./output/bin
	cp -f test_protobuf_json ./output/bin

test_repeated_field:test_repeated_field_test_repeated_field.o \
  test_repeated_field_repeated.pb.o \
  ../libjson-pb.a
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_repeated_field[0m']"
	$(CXX) test_repeated_field_test_repeated_field.o \
  test_repeated_field_repeated.pb.o -Xlinker "-(" ../libjson-pb.a ../../../../lib2-64/ullib/lib/libullib.a \
  ../../../../baidu/base/common/libbase.a \
  ../../../../baidu/base/iobuf/libiobuf.a \
  ../../../../quality/autotest/reportlib/cpp/libautotest.a \
  ../../../../third-64/gflags/lib/libgflags.a \
  ../../../../third-64/gflags/lib/libgflags_nothreads.a \
  ../../../../third-64/libevent/lib/libevent.a \
  ../../../../third-64/libevent/lib/libevent_core.a \
  ../../../../third-64/libevent/lib/libevent_extra.a \
  ../../../../third-64/libevent/lib/libevent_openssl.a \
  ../../../../third-64/libevent/lib/libevent_pthreads.a \
  ../../../../third-64/protobuf/lib/libprotobuf-lite.a \
  ../../../../third-64/protobuf/lib/libprotobuf.a \
  ../../../../third-64/protobuf/lib/libprotoc.a \
  ../../../../thirdsrc/gtest/output/lib/libgmock.a \
  ../../../../thirdsrc/gtest/output/lib/libgmock_main.a \
  ../../../../thirdsrc/gtest/output/lib/libgtest.a \
  ../../../../thirdsrc/gtest/output/lib/libgtest_main.a \
  ../../../../thirdsrc/tcmalloc/output/lib/libprofiler.a -lpthread \
  -lcrypto \
  -lrt \
  -lssl \
  -ldl -Xlinker "-)" -o test_repeated_field
	mkdir -p ./output/bin
	cp -f test_repeated_field ./output/bin

test_protobuf_json_test_protobuf_json.o:test_protobuf_json.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_protobuf_json_test_protobuf_json.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_protobuf_json_test_protobuf_json.o test_protobuf_json.cpp

./addressbook1.pb.cc \
  ./addressbook1.pb.h:addressbook1.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./addressbook1.pb.cc \
  ./addressbook1.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  addressbook1.proto

addressbook1.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40maddressbook1.proto[0m']"
	@echo "ALREADY BUILT"

./test_protobuf_json_addressbook1.pb.o:./addressbook1.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_protobuf_json_addressbook1.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_protobuf_json_addressbook1.pb.o ./addressbook1.pb.cc

./addressbook.pb.cc \
  ./addressbook.pb.h:addressbook.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./addressbook.pb.cc \
  ./addressbook.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  addressbook.proto

addressbook.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40maddressbook.proto[0m']"
	@echo "ALREADY BUILT"

./test_protobuf_json_addressbook.pb.o:./addressbook.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_protobuf_json_addressbook.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_protobuf_json_addressbook.pb.o ./addressbook.pb.cc

./message.pb.cc \
  ./message.pb.h:message.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./message.pb.cc \
  ./message.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  message.proto

message.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mmessage.proto[0m']"
	@echo "ALREADY BUILT"

./test_protobuf_json_message.pb.o:./message.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_protobuf_json_message.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_protobuf_json_message.pb.o ./message.pb.cc

./addressbook_encode_decode.pb.cc \
  ./addressbook_encode_decode.pb.h:addressbook_encode_decode.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./addressbook_encode_decode.pb.cc \
  ./addressbook_encode_decode.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  addressbook_encode_decode.proto

addressbook_encode_decode.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40maddressbook_encode_decode.proto[0m']"
	@echo "ALREADY BUILT"

./test_protobuf_json_addressbook_encode_decode.pb.o:./addressbook_encode_decode.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_protobuf_json_addressbook_encode_decode.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_protobuf_json_addressbook_encode_decode.pb.o ./addressbook_encode_decode.pb.cc

./addressbook_map.pb.cc \
  ./addressbook_map.pb.h:addressbook_map.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./addressbook_map.pb.cc \
  ./addressbook_map.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  addressbook_map.proto

addressbook_map.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40maddressbook_map.proto[0m']"
	@echo "ALREADY BUILT"

./test_protobuf_json_addressbook_map.pb.o:./addressbook_map.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_protobuf_json_addressbook_map.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_protobuf_json_addressbook_map.pb.o ./addressbook_map.pb.cc

test_repeated_field_test_repeated_field.o:test_repeated_field.cpp
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mtest_repeated_field_test_repeated_field.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o test_repeated_field_test_repeated_field.o test_repeated_field.cpp

./repeated.pb.cc \
  ./repeated.pb.h:repeated.proto
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./repeated.pb.cc \
  ./repeated.pb.h[0m']"
	../../../../third-64/protobuf/bin/protoc --cpp_out=./ --proto_path=./  repeated.proto

repeated.proto:
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40mrepeated.proto[0m']"
	@echo "ALREADY BUILT"

./test_repeated_field_repeated.pb.o:./repeated.pb.cc
	@echo "[[1;32;40mCOMAKE:BUILD[0m][Target:'[1;32;40m./test_repeated_field_repeated.pb.o[0m']"
	$(CXX) -c $(INCPATH) $(DEP_INCPATH) $(CPPFLAGS) $(CXXFLAGS)  -o ./test_repeated_field_repeated.pb.o ./repeated.pb.cc

endif #ifeq ($(shell uname -m),x86_64)


