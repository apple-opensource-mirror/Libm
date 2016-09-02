/*
 * Copyright (c) 2002 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*******************************************************************************
*                                                                              *
*     File expTable.c,                                                         *
*     This file contains the unsigned long array expTable[] used in the        *
*     approximation for exp, exp2, expm1 and Power functions.                  *
*                                                                              *
*     Copyright � 1997-2001 Apple Computer, Inc.  All rights reserved.         *
*                                                                              *
*     Written by A. Sazegari, started on May 1997.                             *
*                                                                              *
*     A MathLib v4 file.                                                       *
*                                                                              *
*     May      05 1997: port of the ibm/taligent expTable entries.             *
*     Sept     06 2001: added #ifdef __ppc__.                                  *
*     Sept     09 2001: added more comments.                                   *
*     Sept     10 2001: added macros to detect PowerPC and correct compiler.   *
*     Oct      08 2001: changed compiler errors to warnings.                   *
*                       made expTable a const private_extern.                  *
*     Nov      06 2001: commented out warning about Intel architectures.       *
*                                                                              *
*     W A R N I N G:                                                           *
*     These routines require a 64-bit double precision IEEE-754 model.         *
*     They are written for PowerPC only and are expecting the compiler         *
*     to generate the correct sequence of multiply-add fused instructions.     *
*                                                                              *
*     These routines are not intended for 32-bit Intel architectures.          *
*                                                                              *
*     A version of gcc higher than 932 is required.                            *
*                                                                              *
*     GCC compiler options:                                                    *
*           optimization level 3 (-O3)                                         *
*           -fschedule-insns -finline-functions -funroll-all-loops             *
*                                                                              *
*******************************************************************************/

#ifdef      __APPLE_CC__
#if         __APPLE_CC__ > 930

__private_extern__
const unsigned long int expTable[] = 
      {
      0xBFD61FFF, 0x9E06A8B6, 0x3FE6A5A9, 0xEB779244,
      0xBFD60000, 0x9384EA9C, 0x3FE6B0FF, 0x3E910DE0,
      0xBFD5DFFE, 0x2E10FD7E, 0x3FE6BC5B, 0x6EB69909,
      0xBFD5C001, 0x50AD2AD8, 0x3FE6C7BB, 0x56C431AA,
      0xBFD59FFC, 0x0F24558B, 0x3FE6D323, 0xEDBE8479,
      0xBFD58003, 0x3038B2E1, 0x3FE6DE8D, 0xCE69FD2B,
      0xBFD56003, 0x74202EB1, 0x3FE6E9FF, 0xD94D1AB1,
      0xBFD53FFE, 0x44754B44, 0x3FE6F579, 0x933B0022,
      0xBFD52001, 0xCD7A8610, 0x3FE700F5, 0xE9E2D251,
      0xBFD4FFFD, 0xBAE7B55F, 0x3FE70C7A, 0xBCE9421A,
      0xBFD4DFFF, 0xF3098F3F, 0x3FE71803, 0x0F50B53B,
      0xBFD4C000, 0x56D77807, 0x3FE72391, 0xD03E81DF,
      0xBFD49FFF, 0xA6D40B75, 0x3FE72F26, 0xBDD73AB2,
      0xBFD48002, 0x2CCE7186, 0x3FE73AC0, 0x4D1FB271,
      0xBFD45FFF, 0xD12EA2AB, 0x3FE74661, 0x709F7788,
      0xBFD44003, 0x773EDB7C, 0x3FE75206, 0x36452954,
      0xBFD41FFE, 0x50C74FAE, 0x3FE75DB4, 0x057AC798,
      0xBFD40001, 0xC612F6A9, 0x3FE76964, 0x87D79C2E,
      0xBFD3DFFE, 0x5F10F177, 0x3FE7751D, 0x67039691,
      0xBFD3BFFD, 0xD3C9E940, 0x3FE780DB, 0x17FDE1C1,
      0xBFD3A001, 0xCB4C7FCA, 0x3FE78C9D, 0x00788AB9,
      0xBFD37FFC, 0xD1B51A1A, 0x3FE79868, 0x16954491,
      0xBFD36002, 0x55D0EF71, 0x3FE7A435, 0x348A44DC,
      0xBFD33FFF, 0x16F64EFB, 0x3FE7B00B, 0x77AD4EBC,
      0xBFD32002, 0x9E14230A, 0x3FE7BBE5, 0x24FECB9F,
      0xBFD2FFFD, 0x831DFCAB, 0x3FE7C7C7, 0xF52CBF6E,
      0xBFD2E001, 0xF37B2FE2, 0x3FE7D3AD, 0x2B8F3560,
      0xBFD2BFFE, 0xBA49B35D, 0x3FE7DF9B, 0x30EAA054,
      0xBFD2A000, 0xA8343FF8, 0x3FE7EB8D, 0x425BB634,
      0xBFD28000, 0x4AFBE311, 0x3FE7F786, 0x29D6F97B,
      0xBFD26000, 0x2ABC8904, 0x3FE80384, 0xF87614B4,
      0xBFD24003, 0x0F77F849, 0x3FE80F88, 0xA568F81A,
      0xBFD22004, 0x14C68B23, 0x3FE81B93, 0x09BF16CF,
      0xBFD1FFFF, 0x69D90B52, 0x3FE827A5, 0x9A3436D8,
      0xBFD1DFFF, 0x203C8450, 0x3FE833BC, 0x8E4D1BF5,
      0xBFD1C004, 0x22D0E11A, 0x3FE83FD7, 0x8D95D8C2,
      0xBFD1A002, 0xE1ADB3DC, 0x3FE84BFA, 0xFBC36A6A,
      0xBFD18000, 0x1483FF81, 0x3FE85825, 0x140DA785,
      0xBFD16001, 0x8D8EF807, 0x3FE86453, 0xA26B0A7D,
      0xBFD14003, 0xF1E80949, 0x3FE87087, 0xEF72C053,
      0xBFD12003, 0x8960DFCC, 0x3FE87CC3, 0x69FC5490,
      0xBFD0FFFC, 0xC84AC0C3, 0x3FE88907, 0x72AAAEF2,
      0xBFD0DFFF, 0x9FDA4C80, 0x3FE8954D, 0xF090B2FA,
      0xBFD0C000, 0x9E43EA70, 0x3FE8A19B, 0x48CBDF1E,
      0xBFD0A002, 0x5C16F905, 0x3FE8ADEE, 0x7F3C58CA,
      0xBFD08002, 0x902C8411, 0x3FE8BA48, 0x789DC933,
      0xBFD05FFE, 0x7E84D8C8, 0x3FE8C6AA, 0x47E75EC7,
      0xBFD04001, 0xC8FCEB7A, 0x3FE8D30F, 0x6F9D710D,
      0xBFD02001, 0x2F48CF97, 0x3FE8DF7C, 0x4DF7E836,
      0xBFD00002, 0x1E7F0AC6, 0x3FE8EBEE, 0xCB6CF7E1,
      0xBFCFC008, 0x0FFBFB88, 0x3FE8F867, 0x21DA0406,
      0xBFCF8002, 0x04139A5F, 0x3FE904E7, 0xA38BBF0A,
      0xBFCF4001, 0x3099FAE4, 0x3FE9116D, 0x61EA856B,
      0xBFCF0000, 0x069AC909, 0x3FE91DF9, 0x75C889F9,
      0xBFCEC004, 0x6703548D, 0x3FE92A8A, 0xBA7FD347,
      0xBFCE7FFD, 0xFA2429D7, 0x3FE93724, 0x69BCDD8A,
      0xBFCE4005, 0xF3744A76, 0x3FE943C1, 0x907293A7,
      0xBFCE0007, 0xD4398C97, 0x3FE95066, 0x3B254BAA,
      0xBFCDC004, 0x381B0566, 0x3FE95D12, 0x4FF49EEE,
      0xBFCD7FFB, 0xB5B7FCAA, 0x3FE969C5, 0xB5C59D31,
      0xBFCD3FFB, 0xB377ECCC, 0x3FE9767D, 0xC6D3697D,
      0xBFCCFFFE, 0xB34E7EFD, 0x3FE9833B, 0x9C0344CA,
      0xBFCCBFF7, 0xD72F2C09, 0x3FE99001, 0xC976ACBE,
      0xBFCC8002, 0xCF86C768, 0x3FE99CCA, 0xCAF2C72D,
      0xBFCC3FFD, 0xCC1194EC, 0x3FE9A99D, 0x65CBDE5C,
      0xBFCC0002, 0x0342846D, 0x3FE9B674, 0x91717D58,
      0xBFCBC003, 0xAC9486F5, 0x3FE9C352, 0xAD76F123,
      0xBFCB8002, 0x0D442051, 0x3FE9D037, 0xE382C609,
      0xBFCB3FF8, 0xAAB83FE1, 0x3FE9DD25, 0x1F7B5F3F,
      0xBFCB0003, 0xF96B3FD4, 0x3FE9EA14, 0xA42D00FB,
      0xBFCAC001, 0xF35C26F0, 0x3FE9F70D, 0x5562CC2E,
      0xBFCA7FF8, 0x0F4D1F0C, 0x3FEA040E, 0x1E1CE5F9,
      0xBFCA4006, 0x3FFD181B, 0x3FEA1110, 0x82705651,
      0xBFCA0000, 0xDBB52F7E, 0x3FEA1E1D, 0x67020915,
      0xBFC9BFFC, 0x547E5712, 0x3FEA2B30, 0xA702D87B,
      0xBFC98002, 0x58501833, 0x3FEA3848, 0x49DC5D38,
      0xBFC93FF8, 0xC558E7CB, 0x3FEA4569, 0xACA180B3,
      0xBFC8FFF9, 0xF034CA4E, 0x3FEA528F, 0x6D3BC763,
      0xBFC8BFFE, 0x3AB3F9AC, 0x3FEA5FBB, 0x1D795DD7,
      0xBFC88006, 0x2ADF402B, 0x3FEA6CEC, 0xA4021034,
      0xBFC84007, 0x8D5AAE54, 0x3FEA7A26, 0x1F2B4CF7,
      0xBFC7FFF9, 0x8E05784B, 0x3FEA8769, 0x68B8E771,
      0xBFC7C004, 0xFB6237BE, 0x3FEA94AE, 0x0F6B1041,
      0xBFC77FFC, 0x105729E4, 0x3FEAA1FD, 0x949DDA2B,
      0xBFC73FFE, 0x932E3638, 0x3FEAAF51, 0x6231CD7F,
      0xBFC6FFFC, 0x4BAF8FE0, 0x3FEABCAC, 0xDB3D44DC,
      0xBFC6BFFD, 0xA08CA603, 0x3FEACA0E, 0x42782DEC,
      0xBFC68001, 0x5F8F2788, 0x3FEAD775, 0xDA4F560A,
      0xBFC63FFB, 0x58CDCEB0, 0x3FEAE4E6, 0x34E09021,
      0xBFC5FFF9, 0x24EACB82, 0x3FEAF25C, 0x7BDD14AA,
      0xBFC5BFFE, 0x4360CD2A, 0x3FEAFFD7, 0xF48B0C05,
      0xBFC58002, 0x257BAC22, 0x3FEB0D5A, 0x6EF6FDFD,
      0xBFC53FF8, 0x3C29C56F, 0x3FEB1AE6, 0x97B6921B,
      0xBFC4FFFE, 0xA776874E, 0x3FEB2876, 0x12463472,
      0xBFC4C002, 0x7543FA01, 0x3FEB360C, 0xE3EA75BA,
      0xBFC47FF8, 0x06C72B4B, 0x3FEB43AD, 0x8A81703C,
      0xBFC43FFE, 0xEFA32671, 0x3FEB5151, 0x50CBAD4F,
      0xBFC3FFF7, 0xFD41BD0B, 0x3FEB5EFE, 0xE07857C4,
      0xBFC3BFFB, 0x11C8CF3B, 0x3FEB6CB1, 0x236867D2,
      0xBFC38000, 0x81B24F4A, 0x3FEB7A69,0xBF542696,
      0xBFC34000, 0x5FC00B05, 0x3FEB882A, 0x6B60DED4,
      0xBFC30008, 0x4F7D5EC6, 0x3FEB95F0, 0x3C50D062,
      0xBFC2BFF8, 0x4D0CE1DC, 0x3FEBA3C2, 0x1CBF17F1,
      0xBFC28006, 0x34F1E6DF, 0x3FEBB194, 0x70A3F2F1,
      0xBFC24000, 0xED0834DE, 0x3FEBBF71, 0xD6B3DF1F,
      0xBFC20005, 0x6E6185E1, 0x3FEBCD54, 0x0D9E8988,
      0xBFC1BFFD, 0xCF1B094C, 0x3FEBDB3F, 0xDA8B55C5,
      0xBFC18005, 0x0163D1D2, 0x3FEBE92F, 0x64BDA275,
      0xBFC14007, 0x2A67ABE9, 0x3FEBF727, 0x01583D29,
      0xBFC0FFFB, 0xBE02EF5C, 0x3FEC0528, 0x947EC9FC,
      0xBFC0C005, 0x536D2E26, 0x3FEC132C, 0x8FE4C9B0,
      0xBFC07FFB, 0xBCEE46CE, 0x3FEC213B, 0xC491119A,
      0xBFC03FF7, 0xAC488538, 0x3FEC2F50, 0xCC55D883,
      0xBFC00003, 0x90785C97, 0x3FEC3D69, 0x5B9D62A7,
      0xBFBF7FFF, 0xBA6A2D64, 0x3FEC4B8C, 0x69F4D94E,
      0xBFBEFFFA, 0x223CB409, 0x3FEC59B6, 0x58CD3795,
      0xBFBE8005, 0x20C09CD6, 0x3FEC67E5, 0x877AF944,
      0xBFBDFFF3, 0x21D26301, 0x3FEC761F, 0x0802A6A5,
      0xBFBD7FF5, 0x84275689, 0x3FEC845D, 0x62E589DE,
      0xBFBD0004, 0x534E18D4, 0x3FEC92A1, 0x7B970E46,
      0xBFBC800A, 0xEEADCAAF, 0x3FECA0ED, 0xA21BC7F1,
      0xBFBC000C, 0x670EDE89, 0x3FECAF41, 0x837703D5,
      0xBFBB7FF8, 0xFF9A5338, 0x3FECBD9E, 0xE86A158C,
      0xBFBB0006, 0xE3D4AA0D, 0x3FECCBFF, 0xC0233C14,
      0xBFBA7FF1, 0xB5A81B24, 0x3FECDA6B, 0xBD3BF07F,
      0xBFBA000F, 0xDA902A27, 0x3FECE8D9, 0x278D626A,
      0xBFB97FF8, 0x63290E28, 0x3FECF753, 0xD9919C92,
      0xBFB8FFFC, 0x5F7F0E9A, 0x3FED05D2, 0xAF567BF3,
      0xBFB88007, 0xBC01BCD4, 0x3FED1457, 0xEFA163D6,
      0xBFB80004, 0x5662B0F0, 0x3FED22E6, 0x21B8ED9B,
      0xBFB7800A, 0x14F0B840, 0x3FED317A, 0x920FB487,
      0xBFB70004, 0xEA44F9E5, 0x3FED4017, 0x8D446C52,
      0xBFB67FFE, 0x7D5FB55D, 0x3FED4EBB, 0xFDF9F05D,
      0xBFB5FFF6, 0x88527FF3, 0x3FED5D67, 0xF0168B7C,
      0xBFB58003, 0x0BF43B9A, 0x3FED6C18, 0xE0262A66,
      0xBFB4FFFD, 0xAF26A6DE, 0x3FED7AD3, 0x38CC4727,
      0xBFB47FF9, 0x271098A1, 0x3FED8994, 0xD83A5685,
      0xBFB3FFF0, 0xB08205E2, 0x3FED985E, 0x4EEE5021,
      0xBFB38007, 0x6F7E2BFF, 0x3FEDA72B, 0x8F42589C,
      0xBFB30000, 0xDFAF5B77, 0x3FEDB603, 0x9D826596,
      0xBFB28003, 0x3B8BAD1C, 0x3FEDC4E2, 0x1077C432,
      0xBFB2000F, 0x9E841F7A, 0x3FEDD3C6, 0xC945BBBF,
      0xBFB17FF3, 0xD058F972, 0x3FEDE2B7, 0xA6BD0A91,
      0xBFB10008, 0x2A66433C, 0x3FEDF1AA, 0x5E1CEA50,
      0xBFB0800F, 0xF365565B, 0x3FEE00A6, 0x088E17AB,
      0xBFB00010, 0x9127588D, 0x3FEE0FAA, 0x09C0D3D2,
      0xBFAF000E, 0x4361004C, 0x3FEE1EB6, 0xBD8D1153,
      0xBFADFFEE, 0xBE084214, 0x3FEE2DCB, 0xB9054F03,
      0xBFAD0015, 0xF926FB07, 0x3FEE3CE4, 0x141B0623,
      0xBFAC001A, 0x5F08EB4C, 0x3FEE4C06, 0x0BC384E2,
      0xBFAAFFE6, 0x865799CE, 0x3FEE5B32, 0xEBDA3945,
      0xBFA9FFF4, 0xFBEA39EA, 0x3FEE6A63, 0x7573BD9C,
      0xBFA90004, 0xDC02D6C6, 0x3FEE799B, 0x833674AF,
      0xBFA80019, 0x3F3581E5, 0x3FEE88DA, 0xE98B0DFE,
      0xBFA6FFE1, 0x9FCFBE09, 0x3FEE9826, 0x7B9C67B3,
      0xBFA5FFF3, 0xFAD12424, 0x3FEEA775, 0x492C47D3,
      0xBFA50012, 0xB64F43A5, 0x3FEEB6CB, 0x016DD166,
      0xBFA3FFE1, 0xB9A0F503, 0x3FEEC62D, 0x302FE8A4,
      0xBFA2FFE3, 0x5C55744D, 0x3FEED594, 0x06FA9F71,
      0xBFA20019, 0x0D7DE6C7, 0x3FEEE4FF, 0x6EEFEDB3,
      0xBFA10006, 0xE34041AE, 0x3FEEF476, 0xE5121E62,
      0xBF9FFFFA, 0x037B36B9, 0x3FEF03F5, 0x98F3A7C0,
      0xBF9DFFEF, 0x81B2865F, 0x3FEF137B, 0xC685545A,
      0xBF9BFFED, 0x59F0F3C6, 0x3FEF2309, 0x7844DEF1,
      0xBF99FFF0, 0x84016BAD, 0x3FEF329E, 0xC95A4A4A,
      0xBF98002F, 0xBD707377, 0x3FEF423A, 0x11A5537B,
      0xBF960014, 0x0E40BFC9, 0x3FEF51DF, 0xF0608BEC,
      0xBF94001C, 0x1C31D829, 0x3FEF618C, 0x8C0B5F4C,
      0xBF92002F, 0xCAE47CFD, 0x3FEF7140, 0xA47339BE,
      0xBF8FFFED, 0x674309E4, 0x3FEF80FE, 0xF53AA804,
      0xBF8C0037, 0x674CCFFF, 0x3FEF90C2, 0x41820D9D,
      0xBF87FFCB, 0xB1254C31, 0x3FEFA090,0x3F372467,
      0xBF83FF7E, 0xD04273F2, 0x3FEFB065, 0xAC981883,
      0xBF7FFFE7, 0xD555D0E6, 0x3FEFC040, 0x055FAC69,
      0xBF7800B1, 0x286BB32F, 0x3FEFD022, 0x8DC7D9A1,
      0xBF6FFEEF, 0x95287756, 0x3FEFE011, 0x0A06F8F8,
      0xBF5FFE3F, 0xA04A1A4D, 0x3FEFF004, 0xDF154CBF,
      0x00000000, 0x00000000, 0x3FF00000, 0x00000000,
      0x3F5FFE3F, 0xA04A1A4D, 0x3FF00801, 0x90055A15,
      0x3F6FFEEF, 0x95287756, 0x3FF01007, 0x79ED725C,
      0x3F7800B1, 0x286BB32F, 0x3FF01812, 0xBB3654E4,
      0x3F7FFFE7, 0xD555D0E6, 0x3FF0201F, 0xFD04D45F,
      0x3F83FF7E, 0xD04273F2, 0x3FF02831, 0x24DC36C2,
      0x3F87FFCB, 0xB1254C31, 0x3FF03047, 0xDE5CBAAB,
      0x3F8C0037, 0x674CCFFF, 0x3FF03862, 0xE30EBE3B,
      0x3F8FFFED, 0x674309E4, 0x3FF04080, 0x858E7377,
      0x3F92002F, 0xCAE47CFD, 0x3FF048A3, 0xB6A1CC4F,
      0x3F94001C, 0x1C31D829, 0x3FF050C9, 0xC1A02593,
      0x3F960014, 0x0E40BFC9, 0x3FF058F4, 0x10065A42,
      0x3F98002F, 0xBD707377, 0x3FF06123, 0x06E1220F,
      0x3F99FFF0, 0x84016BAD, 0x3FF06954, 0xA179B85C,
      0x3F9BFFED, 0x59F0F3C6, 0x3FF0718B, 0x4C4A870A,
      0x3F9DFFEF, 0x81B2865F, 0x3FF079C6, 0x295A7763,
      0x3F9FFFFA, 0x037B36B9, 0x3FF08205, 0x475C7DF3,
      0x3FA10006, 0xE34041AE, 0x3FF08A48, 0xAC502E90,
      0x3FA20019, 0x0D7DE6C7, 0x3FF09290, 0x78CCC44E,
      0x3FA2FFE3, 0x5C55744D, 0x3FF09ADA, 0x15ED2501,
      0x3FA3FFE1, 0xB9A0F503, 0x3FF0A329, 0x8910E62C,
      0x3FA50012, 0xB64F43A5, 0x3FF0AB7E, 0xCAE14B1E,
      0x3FA5FFF3, 0xFAD12424, 0x3FF0B3D5, 0x9F68305E,
      0x3FA6FFE1, 0x9FCFBE09, 0x3FF0BC31, 0x07747D8B,
      0x3FA80019, 0x3F3581E5, 0x3FF0C493, 0x0A2DB805,
      0x3FA90004, 0xDC02D6C6, 0x3FF0CCF6, 0xC15BB6C2,
      0x3FA9FFF4, 0xFBEA39EA, 0x3FF0D55E, 0xD11670A0,
      0x3FAAFFE6, 0x865799CE, 0x3FF0DDCB, 0x21949570,
      0x3FAC001A, 0x5F08EB4C, 0x3FF0E63D, 0xD94ED2C0,
      0x3FAD0015, 0xF926FB07, 0x3FF0EEB2, 0xF0216CB5,
      0x3FADFFEE, 0xBE084214, 0x3FF0F72B, 0x1B00DFBD,
      0x3FAF000E, 0x4361004C, 0x3FF0FFA9, 0xDBB666DE,
      0x3FB00010, 0x9127588D, 0x3FF1082C, 0x71A83236,
      0x3FB0800F, 0xF365565B, 0x3FF110B2, 0x9EBD49C7,
      0x3FB10008, 0x2A66433C, 0x3FF1193C, 0x9560A083,
      0x3FB17FF3, 0xD058F972, 0x3FF121C9, 0xFA838612,
      0x3FB2000F, 0x9E841F7A, 0x3FF12A5E, 0xE1605650,
      0x3FB28003, 0x3B8BAD1C, 0x3FF132F5, 0x616EC20A,
      0x3FB30000, 0xDFAF5B77, 0x3FF13B90, 0xDA33C872,
      0x3FB38007, 0x6F7E2BFF, 0x3FF14431, 0x3BBB21D8,
      0x3FB3FFF0, 0xB08205E2, 0x3FF14CD3, 0xF3B8F0D0,
      0x3FB47FF9, 0x271098A1, 0x3FF1557D, 0x1A5C911F,
      0x3FB4FFFD, 0xAF26A6DE, 0x3FF15E2A, 0x52AA0F01,
      0x3FB58003, 0x0BF43B9A, 0x3FF166DB, 0xF1469616,
      0x3FB5FFF6, 0x88527FF3, 0x3FF16F90, 0xB245A9B7,
      0x3FB67FFE, 0x7D5FB55D, 0x3FF1784B, 0x33F0FF20,
      0x3FB70004, 0xEA44F9E5, 0x3FF18109, 0xF969EDC2,
      0x3FB7800A, 0x14F0B840, 0x3FF189CD, 0x0982A872,
      0x3FB80004, 0x5662B0F0, 0x3FF19293, 0xBCAD32FE,
      0x3FB88007, 0xBC01BCD4, 0x3FF19B5F, 0x750B2043,
      0x3FB8FFFC, 0x5F7F0E9A, 0x3FF1A42E, 0x902180C4,
      0x3FB97FF8, 0x63290E28, 0x3FF1AD02, 0x95DA3E9A,
      0x3FBA000F, 0xDA902A27, 0x3FF1B5DC, 0xECBD41A8,
      0x3FBA7FF1, 0xB5A81B24, 0x3FF1BEB7, 0xFB652796,
      0x3FBB0006, 0xE3D4AA0D, 0x3FF1C79B, 0x082D2770,
      0x3FBB7FF8, 0xFF9A5338, 0x3FF1D080, 0x178B34DA,
      0x3FBC000C, 0x670EDE89, 0x3FF1D96B, 0xEC5F9C05,
      0x3FBC800A, 0xEEADCAAF, 0x3FF1E25A, 0xC39749FC,
      0x3FBD0004, 0x534E18D4, 0x3FF1EB4D, 0xB73FDD40,
      0x3FBD7FF5, 0x84275689, 0x3FF1F444, 0x9201CEA7,
      0x3FBDFFF3, 0x21D26301, 0x3FF1FD40, 0xC84FC26F,
      0x3FBE8005, 0x20C09CD6, 0x3FF20642, 0xED196357,
      0x3FBEFFFA, 0x223CB409, 0x3FF20F47, 0x892B343F,
      0x3FBF7FFF, 0xBA6A2D64, 0x3FF21851, 0xD4745803,
      0x3FC00003, 0x90785C97, 0x3FF22160, 0xC6F5D1F2,
      0x3FC03FF7, 0xAC488538, 0x3FF22A72, 0x0BDDDD73,
      0x3FC07FFB, 0xBCEE46CE, 0x3FF2338A, 0x1E8D4E31,
      0x3FC0C005, 0x536D2E26, 0x3FF23CA7, 0x8823DB26,
      0x3FC0FFFB, 0xBE02EF5C, 0x3FF245C6, 0xC5A1C29C,
      0x3FC14007, 0x2A67ABE9, 0x3FF24EED, 0x946845B3,
      0x3FC18005, 0x0163D1D2, 0x3FF25817, 0x0630BC16,
      0x3FC1BFFD, 0xCF1B094C, 0x3FF26144, 0x548E6104,
      0x3FC20005, 0x6E6185E1, 0x3FF26A78, 0x5C00381F,
      0x3FC24000, 0xED0834DE, 0x3FF273AF,0x3F9C9435,
      0x3FC28006, 0x34F1E6DF, 0x3FF27CEC, 0x2959016E,
      0x3FC2BFF8, 0x4D0CE1DC, 0x3FF2862A, 0xEC3E1B7C,
      0x3FC30008, 0x4F7D5EC6, 0x3FF28F72, 0xA5252CE2,
      0x3FC34000, 0x5FC00B05, 0x3FF298BB, 0x899A2304,
      0x3FC38000, 0x81B24F4A, 0x3FF2A20A,0x3FCAA732,
      0x3FC3BFFB, 0x11C8CF3B, 0x3FF2AB5C, 0xCE8AF3AA,
      0x3FC3FFF7, 0xFD41BD0B, 0x3FF2B4B4, 0x5F853C4A,
      0x3FC43FFE, 0xEFA32671, 0x3FF2BE12, 0x1515CAA9,
      0x3FC47FF8, 0x06C72B4B, 0x3FF2C772, 0x72C3707E,
      0x3FC4C002, 0x7543FA01, 0x3FF2D0DA, 0x0DDE21FD,
      0x3FC4FFFE, 0xA776874E, 0x3FF2DA44, 0x45F749A3,
      0x3FC53FF8, 0x3C29C56F, 0x3FF2E3B2, 0xD1455383,
      0x3FC58002, 0x257BAC22, 0x3FF2ED28, 0x7EB5B59C,
      0x3FC5BFFE, 0x4360CD2A, 0x3FF2F6A0, 0xDDB7E72E,
      0x3FC5FFF9, 0x24EACB82, 0x3FF3001D, 0xCAD955B2,
      0x3FC63FFB, 0x58CDCEB0, 0x3FF309A0, 0x8E05F95C,
      0x3FC68001, 0x5F8F2788, 0x3FF31328, 0xA5CE3BDE,
      0x3FC6BFFD, 0xA08CA603, 0x3FF31CB4, 0x0DBA9111,
      0x3FC6FFFC, 0x4BAF8FE0, 0x3FF32644, 0x98BF315F,
      0x3FC73FFE, 0x932E3638, 0x3FF32FDA, 0x77B14293,
      0x3FC77FFC, 0x105729E4, 0x3FF33974, 0x6AC2524E,
      0x3FC7C004, 0xFB6237BE, 0x3FF34314, 0xE41CE9E2,
      0x3FC7FFF9, 0x8E05784B, 0x3FF34CB7, 0x1E433C92,
      0x3FC84007, 0x8D5AAE54, 0x3FF35662, 0x01290A9D,
      0x3FC88006, 0x2ADF402B, 0x3FF3600F, 0x67B4B457,
      0x3FC8BFFE, 0x3AB3F9AC, 0x3FF369C0, 0xA79C7210,
      0x3FC8FFF9, 0xF034CA4E, 0x3FF37377, 0x4EA2198A,
      0x3FC93FF8, 0xC558E7CB, 0x3FF37D33, 0x4B9F2837,
      0x3FC98002, 0x58501833, 0x3FF386F5, 0xCB3C3FCB,
      0x3FC9BFFC, 0x547E5712, 0x3FF390BA, 0xCC0A8E28,
      0x3FCA0000, 0xDBB52F7E, 0x3FF39A86, 0x4D79E27A,
      0x3FCA4006, 0x3FFD181B, 0x3FF3A456, 0xD828D053,
      0x3FCA7FF8, 0x0F4D1F0C, 0x3FF3AE29, 0x49FF8DB8,
      0x3FCAC001, 0xF35C26F0, 0x3FF3B804, 0x5AE511EC,
      0x3FCB0003, 0xF96B3FD4, 0x3FF3C1E3, 0x24733EE0,
      0x3FCB3FF8, 0xAAB83FE1, 0x3FF3CBC4, 0xCEFC7130,
      0x3FCB8002, 0x0D442051, 0x3FF3D5AE, 0x9F91AAAD,
      0x3FCBC003, 0xAC9486F5, 0x3FF3DF9C, 0x327C955C,
      0x3FCC0002, 0x0342846D, 0x3FF3E98E, 0x3AC92872,
      0x3FCC3FFD, 0xCC1194EC, 0x3FF3F384, 0xD74C2763,
      0x3FCC8002, 0xCF86C768, 0x3FF3FD81, 0xE1042B4C,
      0x3FCCBFF7, 0xD72F2C09, 0x3FF40781, 0x6A9D24E5,
      0x3FCCFFFE, 0xB34E7EFD, 0x3FF41188, 0xC002EEC3,
      0x3FCD3FFB, 0xB377ECCC, 0x3FF41B93, 0x8E602921,
      0x3FCD7FFB, 0xB5B7FCAA, 0x3FF425A3, 0xDC5FC209,
      0x3FCDC004, 0x381B0566, 0x3FF42FBA, 0x8AF9A354,
      0x3FCE0007, 0xD4398C97, 0x3FF439D5, 0x80A87648,
      0x3FCE4005, 0xF3744A76, 0x3FF443F4, 0xA6F15623,
      0x3FCE7FFD, 0xFA2429D7, 0x3FF44E17, 0xE65D8D20,
      0x3FCEC004, 0x6703548D, 0x3FF45842, 0x81F1199A,
      0x3FCF0000, 0x069AC909, 0x3FF46270, 0x7C38EFDA,
      0x3FCF4001, 0x3099FAE4, 0x3FF46CA4, 0x70BEAED9,
      0x3FCF8002, 0x04139A5F, 0x3FF476DD, 0x72C7FACB,
      0x3FCFC008, 0x0FFBFB88, 0x3FF4811C, 0x68BFE077,
      0x3FD00002, 0x1E7F0AC6, 0x3FF48B5E, 0xEA63927B,
      0x3FD02001, 0x2F48CF97, 0x3FF495A6, 0xDEC1F439,
      0x3FD04001, 0xC8FCEB7A, 0x3FF49FF4, 0x76DC76A2,
      0x3FD05FFE, 0x7E84D8C8, 0x3FF4AA45, 0xF57D8C8C,
      0x3FD08002, 0x902C8411, 0x3FF4B49E, 0xFF2F6CC6,
      0x3FD0A002, 0x5C16F905, 0x3FF4BEFB, 0xD4CF37CB,
      0x3FD0C000, 0x9E43EA70, 0x3FF4C95D, 0x5A3B216A,
      0x3FD0DFFF, 0x9FDA4C80, 0x3FF4D3C4, 0x4FB80227,
      0x3FD0FFFC, 0xC84AC0C3, 0x3FF4DE2F, 0xDF8CCF03,
      0x3FD12003, 0x8960DFCC, 0x3FF4E8A3, 0xC895EFF5,
      0x3FD14003, 0xF1E80949, 0x3FF4F31A, 0xDA358F43,
      0x3FD16001, 0x8D8EF807, 0x3FF4FD96, 0x3D9FA7C8,
      0x3FD18000, 0x1483FF81, 0x3FF50817, 0x2CF9FB90,
      0x3FD1A002, 0xE1ADB3DC, 0x3FF5129E, 0xC625E843,
      0x3FD1C004, 0x22D0E11A, 0x3FF51D2B, 0x223F2B87,
      0x3FD1DFFF, 0x203C8450, 0x3FF527BA, 0xB3F16A02,
      0x3FD1FFFF, 0x69D90B52, 0x3FF53251, 0x4F14D742,
      0x3FD22004, 0x14C68B23, 0x3FF53CEE, 0xAAFF2C4E,
      0x3FD24003, 0x0F77F849, 0x3FF5478F, 0x7381DEA8,
      0x3FD26000, 0x2ABC8904, 0x3FF55234, 0xEDDA1F0A,
      0x3FD28000, 0x4AFBE311, 0x3FF55CE0, 0xBDCD0455,
      0x3FD2A000, 0xA8343FF8, 0x3FF56791, 0xF96759E3,
      0x3FD2BFFE, 0xBA49B35D, 0x3FF57247, 0xCA4596EE,
      0x3FD2E001, 0xF37B2FE2, 0x3FF57D04, 0xB1F649E1,
      0x3FD2FFFD, 0x831DFCAB, 0x3FF587C4, 0x66193E83,
      0x3FD32002, 0x9E14230A, 0x3FF5928C, 0xB2412818,
      0x3FD33FFF, 0x16F64EFB, 0x3FF59D57, 0x7A5CE15C,
      0x3FD36002, 0x55D0EF71, 0x3FF5A829, 0xF35F28B1,
      0x3FD37FFC, 0xD1B51A1A, 0x3FF5B2FE, 0xDF0B0A6F,
      0x3FD3A001, 0xCB4C7FCA, 0x3FF5BDDC, 0xC5F60DF4,
      0x3FD3BFFD, 0xD3C9E940, 0x3FF5C8BD, 0x12E09088,
      0x3FD3DFFE, 0x5F10F177, 0x3FF5D3A4, 0x5A75C2A7,
      0x3FD40001, 0xC612F6A9, 0x3FF5DE92, 0x112DB4DB,
      0x3FD41FFE, 0x50C74FAE, 0x3FF5E982, 0xE7624A53,
      0x3FD44003, 0x773EDB7C, 0x3FF5F47C, 0x2AC711D1,
      0x3FD45FFF, 0xD12EA2AB, 0x3FF5FF77, 0xE6D346E6,
      0x3FD48002, 0x2CCE7186, 0x3FF60A7B, 0x330CD4C7,
      0x3FD49FFF, 0xA6D40B75, 0x3FF61582, 0x53842C6E,
      0x3FD4C000, 0x56D77807, 0x3FF62090, 0x14AECAB1,
      0x3FD4DFFF, 0xF3098F3F, 0x3FF62BA2, 0xFEAE61C8,
      0x3FD4FFFD, 0xBAE7B55F, 0x3FF636BA, 0xD0E6E867,
      0x3FD52001, 0xCD7A8610, 0x3FF641DA, 0x60306CB5,
      0x3FD53FFE, 0x44754B44, 0x3FF64CFC, 0xDAB8119B,
      0x3FD56003, 0x74202EB1, 0x3FF65827, 0xF2C37AE0,
      0x3FD58003, 0x3038B2E1, 0x3FF66356, 0xBA781CA8,
      0x3FD59FFC, 0x0F24558B, 0x3FF66E88, 0xB3086D24,
      0x3FD5C001, 0x50AD2AD8, 0x3FF679C4, 0x9E31BBDA,
      0x3FD5DFFE, 0x2E10FD7E, 0x3FF68503, 0x35C78AED,
      0x3FD60000, 0x9384EA9C, 0x3FF69049, 0x60C1D8CF,
      0x3FD61FFF, 0x9E06A8B6, 0x3FF69B94, 0x013B9EEF
      };

#else       /* __APPLE_CC__ version */
#warning A higher version than gcc-932 is required.
#endif      /* __APPLE_CC__ version */
#endif      /* __APPLE_CC__ */
