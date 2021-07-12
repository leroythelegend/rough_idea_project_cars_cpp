cmake_minimum_required(VERSION 3.0.0)
project(rispcars VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

include(CTest)
enable_testing()

add_library(rispcars  ./src/capture.cpp
                      ./src/decoder16timeschar64.cpp
                      ./src/decoder16timesfloat.cpp
                      ./src/decoder16timesu16.cpp
                      ./src/decoder16timesu32.cpp
                      ./src/decoder16vehicleinfo.cpp
                      ./src/decoder1bit2bit2bit3bit.cpp
                      ./src/decoder20char.cpp
                      ./src/decoder2bit3bit.cpp
                      ./src/decoder2timesu8.cpp
                      ./src/decoder32participantinfo.cpp
                      ./src/decoder32participantsstatsinfo.cpp
                      ./src/decoder3bit3bit.cpp
                      ./src/decoder3bit.cpp
                      ./src/decoder3timesfloat.cpp
                      ./src/decoder3timess16.cpp
                      ./src/decoder40char.cpp
                      ./src/decoder4bit4bit.cpp
                      ./src/decoder4timeschar40.cpp
                      ./src/decoder4timesfloat.cpp
                      ./src/decoder4timess16.cpp
                      ./src/decoder4timesu16.cpp
                      ./src/decoder4timesu8.cpp
                      ./src/decoder56participantinfo.cpp
                      ./src/decoder60classinfo.cpp
                      ./src/decoder64char.cpp
                      ./src/decoder6bit2bit.cpp
                      ./src/decoderboolu16.cpp
                      ./src/decoderboolu8.cpp
                      ./src/decoderbottom2bits.cpp
                      ./src/decoderclassinfo.cpp
                      ./src/decodercomposite.cpp
                      ./src/decoderf32.cpp
                      ./src/decoderls2bits.cpp
                      ./src/decoderls3bits.cpp
                      ./src/decoderls4bits.cpp
                      ./src/decoderls7bits.cpp
                      ./src/decoderms2bits.cpp
                      ./src/decoderms3bits.cpp
                      ./src/decoderms4bits.cpp
                      ./src/decoderms6bits.cpp
                      ./src/decodermsbbool.cpp
                      ./src/decoderparticipantinfo.cpp
                      ./src/decoderparticipantinfov1.cpp
                      ./src/decoderparticipantsstatsinfo.cpp
                      ./src/decoders16.cpp
                      ./src/decoders8.cpp
                      ./src/decoderstringvector.cpp
                      ./src/decodertop2bits.cpp
                      ./src/decoderu15.cpp
                      ./src/decoderu16.cpp
                      ./src/decoderu32.cpp
                      ./src/decoderu8.cpp
                      ./src/decodervehicleinfo.cpp
                      ./src/gamestate.cpp
                      ./src/gamestatefactory.cpp
                      ./src/myprocess.cpp
                      ./src/packetbase.cpp
                      ./src/packetgamestate.cpp
                      ./src/packetgeneric.cpp
                      ./src/packetparticipantinfostringsadditional.cpp
                      ./src/packetparticipantinfostrings.cpp
                      ./src/packetparticipantsdata.cpp
                      ./src/packetparticipantvehiclenamesdata.cpp
                      ./src/packetracedata.cpp
                      ./src/packettelemetrydata.cpp
                      ./src/packettelemetrydatav1.cpp
                      ./src/packettimestatsdata.cpp
                      ./src/packettimingdata.cpp
                      ./src/packetvehicleclassnamesdata.cpp
                      ./src/telemetryv1.cpp
                      ./src/telemetryv2.cpp
                      ./src/processv2csvimpl.cpp
                      ./src/processv1csvimpl.cpp
                      ./src/transportudp.cpp
                      ./src/processv2csv.cpp
                      ./src/csvencoder.cpp
                      ./src/processv2csvtyreimpl.cpp
                      ./src/processv1csvtyreimpl.cpp
                      ./src/processv2csvinputsimpl.cpp
                      ./src/processv1csvinputsimpl.cpp
                      ./src/processv2csvengineimpl.cpp
                      ./src/processv1csvengineimpl.cpp
                      ./src/processv2csvforceimpl.cpp
                      ./src/processv1csvforceimpl.cpp
                      ./src/processv2csvracelineimpl.cpp
                      ./src/processv1csvracelineimpl.cpp
                      ./src/processv2csvweatherimpl.cpp
                      ./src/processv1csvweatherimpl.cpp
                      ./src/processv2csvsupimpl.cpp
                      ./src/processv1csvsupimpl.cpp
                      ./src/processv2csvmsgimpl.cpp
                      ./src/processv1csvmsgimpl.cpp
                      ./src/telemetrymsg.cpp
                      ./src/telemetrymsgv1.cpp
                      ./src/packetfactoryv1.cpp
                      ./src/packetfactoryv2.cpp)
target_link_libraries(rispcars Threads::Threads)


add_executable(mypcars ./app/main.cpp)
target_link_libraries(mypcars rispcars)
install(TARGETS mypcars
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )


add_executable(pcarscsv ./app/maincsv.cpp)
target_link_libraries(pcarscsv rispcars)
install(TARGETS pcarscsv
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
    )

add_executable(testcapture ./tests/testcapture.cpp)
target_link_libraries(testcapture rispcars)
add_test(NAME testcapture COMMAND testcapture)

add_executable(testcsvencoder ./tests/testcsvencoder.cpp)
target_link_libraries(testcsvencoder rispcars)
add_test(NAME testcsvencoder COMMAND testcsvencoder)

add_executable(testdecoder1bit2bit2bit3bit ./tests/testdecoder1bit2bit2bit3bit.cpp)
target_link_libraries(testdecoder1bit2bit2bit3bit rispcars)
add_test(NAME testdecoder1bit2bit2bit3bit COMMAND testdecoder1bit2bit2bit3bit)

add_executable(testdecoder2bit3bit ./tests/testdecoder2bit3bit.cpp)
target_link_libraries(testdecoder2bit3bit rispcars)
add_test(NAME testdecoder2bit3bit COMMAND testdecoder2bit3bit)

add_executable(testdecoder2timesu8 ./tests/testdecoder2timesu8.cpp)
target_link_libraries(testdecoder2timesu8 rispcars)
add_test(NAME testdecoder2timesu8 COMMAND testdecoder2timesu8)

add_executable(testpacketfactorys ./tests/testpacketfactorys.cpp)
target_link_libraries(testpacketfactorys rispcars)
add_test(NAME testpacketfactorys COMMAND testpacketfactorys)

add_executable(testdecoder3bit ./tests/testdecoder3bit.cpp)
target_link_libraries(testdecoder3bit rispcars)
add_test(NAME testdecoder3bit COMMAND testdecoder3bit)

add_executable(testdecoder3bit3bit ./tests/testdecoder3bit3bit.cpp)
target_link_libraries(testdecoder3bit3bit rispcars)
add_test(NAME testdecoder3bit3bit COMMAND testdecoder3bit3bit)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
