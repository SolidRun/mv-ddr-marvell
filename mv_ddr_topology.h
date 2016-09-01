/*******************************************************************************
Copyright (C) 2016 Marvell International Ltd.

This software file (the "File") is owned and distributed by Marvell
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the three
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

This program is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation, either version 2 of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************************
Marvell GNU General Public License FreeRTOS Exception

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File in accordance with the terms and conditions of the Lesser
General Public License Version 2.1 plus the following FreeRTOS exception.
An independent module is a module which is not derived from or based on
FreeRTOS.
Clause 1:
Linking FreeRTOS statically or dynamically with other modules is making a
combined work based on FreeRTOS. Thus, the terms and conditions of the GNU
General Public License cover the whole combination.
As a special exception, the copyright holder of FreeRTOS gives you permission
to link FreeRTOS with independent modules that communicate with FreeRTOS solely
through the FreeRTOS API interface, regardless of the license terms of these
independent modules, and to copy and distribute the resulting combined work
under terms of your choice, provided that:
1. Every copy of the combined work is accompanied by a written statement that
details to the recipient the version of FreeRTOS used and an offer by yourself
to provide the FreeRTOS source code (including any modifications you may have
made) should the recipient request it.
2. The combined work is not itself an RTOS, scheduler, kernel or related
product.
3. The independent modules add significant and primary functionality to
FreeRTOS and do not merely extend the existing functionality already present in
FreeRTOS.
Clause 2:
FreeRTOS may not be used for any competitive or comparative purpose, including
the publication of any form of run time or compile time metric, without the
express permission of Real Time Engineers Ltd. (this is the norm within the
industry and is intended to ensure information accuracy).

********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or
modify this File under the following licensing terms.
Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

	* Redistributions of source code must retain the above copyright notice,
	  this list of conditions and the following disclaimer.

	* Redistributions in binary form must reproduce the above copyright
	  notice, this list of conditions and the following disclaimer in the
	  documentation and/or other materials provided with the distribution.

	* Neither the name of Marvell nor the names of its contributors may be
	  used to endorse or promote products derived from this software without
	  specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/

#ifndef _MV_DDR_TOPOLOGY_H
#define _MV_DDR_TOPOLOGY_H

/* bus width in bits */
enum hws_bus_width {
	BUS_WIDTH_4,
	BUS_WIDTH_8,
	BUS_WIDTH_16,
	BUS_WIDTH_32
};

enum mv_ddr_num_of_sub_phys_per_ddr_unit {
	SINGLE_SUB_PHY = 1,
	TWO_SUB_PHYS = 2
};

enum mv_ddr_temperature {
	MV_DDR_TEMP_LOW,
	MV_DDR_TEMP_NORMAL,
	MV_DDR_TEMP_HIGH
};

enum hws_mem_size {
	MEM_512M,
	MEM_1G,
	MEM_2G,
	MEM_4G,
	MEM_8G,
	MEM_SIZE_LAST
};

enum mv_ddr_timing_data {
	MV_DDR_TCK_AVG_MIN, /* sdram min cycle time (t ck avg min) */
	MV_DDR_TAA_MIN, /* min cas latency time (t aa min) */
	MV_DDR_TRFC1_MIN, /* min refresh recovery delay time (t rfc1 min) */
	MV_DDR_TWR_MIN, /* min write recovery time (t wr min) */
	MV_DDR_TRCD_MIN, /* min ras to cas delay time (t rcd min) */
	MV_DDR_TRP_MIN, /* min row precharge delay time (t rp min) */
	MV_DDR_TRC_MIN, /* min active to active/refresh delay time (t rc min) */
	MV_DDR_TRAS_MIN, /* min active to precharge delay time (t ras min) */
	MV_DDR_TRRD_S_MIN, /* min activate to activate delay time (t rrd_s min), diff bank group */
	MV_DDR_TRRD_L_MIN, /* min activate to activate delay time (t rrd_l min), same bank group */
	MV_DDR_TFAW_MIN, /* min four activate window delay time (t faw min) */
	MV_DDR_TWTR_S_MIN, /* min write to read time (t wtr s min), diff bank group */
	MV_DDR_TWTR_L_MIN, /* min write to read time (t wtr l min), same bank group */
	MV_DDR_TDATA_LAST
};

enum mv_ddr_dev_width { /* sdram device width */
	MV_DDR_DEV_WIDTH_4BIT,
	MV_DDR_DEV_WIDTH_8BIT,
	MV_DDR_DEV_WIDTH_16BIT,
	MV_DDR_DEV_WIDTH_32BIT,
	MV_DDR_DEV_WIDTH_LAST
};

enum mv_ddr_die_capacity { /* total sdram capacity per die, megabits */
	MV_DDR_DIE_CAP_256MBIT,
	MV_DDR_DIE_CAP_512MBIT,
	MV_DDR_DIE_CAP_1GBIT,
	MV_DDR_DIE_CAP_2GBIT,
	MV_DDR_DIE_CAP_4GBIT,
	MV_DDR_DIE_CAP_8GBIT,
	MV_DDR_DIE_CAP_16GBIT,
	MV_DDR_DIE_CAP_32GBIT,
	MV_DDR_DIE_CAP_12GBIT,
	MV_DDR_DIE_CAP_24GBIT,
	MV_DDR_DIE_CAP_LAST
};

enum mv_ddr_pkg_rank { /* number of package ranks per dimm */
	MV_DDR_PKG_RANK_1,
	MV_DDR_PKG_RANK_2,
	MV_DDR_PKG_RANK_3,
	MV_DDR_PKG_RANK_4,
	MV_DDR_PKG_RANK_5,
	MV_DDR_PKG_RANK_6,
	MV_DDR_PKG_RANK_7,
	MV_DDR_PKG_RANK_8,
	MV_DDR_PKG_RANK_LAST
};

enum mv_ddr_die_count {
	MV_DDR_DIE_CNT_1,
	MV_DDR_DIE_CNT_2,
	MV_DDR_DIE_CNT_3,
	MV_DDR_DIE_CNT_4,
	MV_DDR_DIE_CNT_5,
	MV_DDR_DIE_CNT_6,
	MV_DDR_DIE_CNT_7,
	MV_DDR_DIE_CNT_8,
	MV_DDR_DIE_CNT_LAST
};

#endif /* _MV_DDR_TOPOLOGY_H */