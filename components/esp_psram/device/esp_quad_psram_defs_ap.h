/*
 * SPDX-FileCopyrightText: 2025 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

//Commands for PSRAM chip

#pragma once

#include "soc/spi_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------------
 * AP Memory PSRAM
 *-------------------------------------------------------------------------------*/

#define PSRAM_QUAD_READ                   0x03
#define PSRAM_QUAD_FAST_READ              0x0B
#define PSRAM_QUAD_FAST_READ_QUAD         0xEB
#define PSRAM_QUAD_WRITE                  0x02
#define PSRAM_QUAD_WRITE_QUAD             0x38
#define PSRAM_QUAD_ENTER_QMODE            0x35
#define PSRAM_QUAD_EXIT_QMODE             0xF5
#define PSRAM_QUAD_RESET_EN               0x66
#define PSRAM_QUAD_RESET                  0x99
#define PSRAM_QUAD_SET_BURST_LEN          0xC0
#define PSRAM_QUAD_DEVICE_ID              0x9F

#define PSRAM_QUAD_FAST_READ_DUMMY        4
#define PSRAM_QUAD_FAST_READ_QUAD_DUMMY   6

// ID
#define PSRAM_QUAD_ID_BITS_NUM            24
#define PSRAM_QUAD_EID_BITS_NUM           48
#define PSRAM_QUAD_ID_KGD_M               0xff
#define PSRAM_QUAD_ID_KGD_S               8
#define PSRAM_QUAD_ID_KGD                 0x5d
#define PSRAM_QUAD_ID_EID_BIT_47_40_M     0xff
#define PSRAM_QUAD_ID_EID_BIT_47_40_S     16

// Use the [47:45](bit47~bit45) of EID to distinguish the psram size:
//
//   BIT47  |  BIT46  |  BIT45  |  SIZE(MBIT)
//   -------------------------------------
//    0     |   0     |   0     |     16
//    0     |   0     |   1     |     32
//    0     |   1     |   0     |     64
#define PSRAM_QUAD_EID_BIT_47_45_M        0x07
#define PSRAM_QUAD_EID_BIT_47_45_S        5

#define PSRAM_QUAD_KGD(id)                (((id) >> PSRAM_QUAD_ID_KGD_S) & PSRAM_QUAD_ID_KGD_M)
#define PSRAM_QUAD_EID_BIT_47_40(id)      (((id) >> PSRAM_QUAD_ID_EID_BIT_47_40_S) & PSRAM_QUAD_ID_EID_BIT_47_40_M)
#define PSRAM_QUAD_SIZE_ID(id)            ((PSRAM_QUAD_EID_BIT_47_40(id) >> PSRAM_QUAD_EID_BIT_47_45_S) & PSRAM_QUAD_EID_BIT_47_45_M)
#define PSRAM_QUAD_IS_VALID(id)           (PSRAM_QUAD_KGD(id) == PSRAM_QUAD_ID_KGD)

#define PSRAM_QUAD_IS_64MBIT_TRIAL(id)    (PSRAM_QUAD_EID_BIT_47_40(id) == 0x26)

// IO-pins for PSRAM.
// PSRAM clock and cs IO should be configured based on hardware design.
#define PSRAM_QUAD_CLK_IO                 MSPI_IOMUX_PIN_NUM_CLK
#define PSRAM_QUAD_CS_IO                  MSPI_IOMUX_PIN_NUM_CS1
#define PSRAM_QUAD_SPIQ_SD0_IO            MSPI_IOMUX_PIN_NUM_MISO
#define PSRAM_QUAD_SPID_SD1_IO            MSPI_IOMUX_PIN_NUM_MOSI
#define PSRAM_QUAD_SPIWP_SD3_IO           MSPI_IOMUX_PIN_NUM_WP
#define PSRAM_QUAD_SPIHD_SD2_IO           MSPI_IOMUX_PIN_NUM_HD

#define PSRAM_QUAD_CMD_LENGTH             8
#define PSRAM_QUAD_ADDR_LENGTH            24

#define PSRAM_QUAD_CS_HOLD_VAL            1
#define PSRAM_QUAD_CS_SETUP_VAL           1

// QEMU has a simulated 16MB and 32MB Quad SPI PSRAM. Use a fake ID for these.
#define PSRAM_QUAD_QEMU_16MB_ID           0x6a
#define PSRAM_QUAD_QEMU_32MB_ID           0x8e

#ifdef __cplusplus
}
#endif
