cmake_minimum_required(VERSION 3.0.0)
project(rispcars VERSION 0.1.0)

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
                      ./src/Packetvehicleclassnamesdata.cpp
                      ./src/telemetryv1.cpp
                      ./src/telemetryv2.cpp
                      ./src/transportudp.cpp
                      )

target_include_directories(rispcars PUBLIC
                      $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>)

add_executable(mypcars ./app/main.cpp)

target_link_libraries(mypcars rispcars)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
