/* Declarations the C of src/main/ uses (tools/auto_decomp.py adds to this). */
#ifndef MAIN_DECLS_H
#define MAIN_DECLS_H

#include "m2c.h"

typedef struct {
    s32 first;
    s32 second;
} Pair;

/* AKAO sound driver ---------------------------------------------------- */

/* A request in the driver's queue. The song commands (0x10, 0x14, 0x15,
 * table at 0x80049548) read the sequence to load and the song from it. */
typedef struct {
    s32 unk0;
    u8 *sequence; /* 0x04 */
    s32 size;     /* 0x08: bytes */
    u16 song;     /* 0x0C */
} AkaoCommand;

/* A song's own state (its channels are apart): 0x60 bytes. */
typedef struct {
    s32 unk0;
    s32 active;   /* 0x04: one bit per channel playing */
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    u16 unk48;
    u16 id;       /* 0x4A: the song, 0 for none */
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
} AkaoSong;

/* A channel of a song: 0x108 bytes. */
typedef struct {
    u8 *addr;          /* 0x00: where it reads its sequence */
    u8 pad4[0x10];
    u8 *start;         /* 0x14 */
    u8 pad18[0x14];
    s32 unk2C;         /* 0x2C */
    u8 pad30[0x4];
    s32 unk34;         /* 0x34 */
    s32 unk38;         /* 0x38 */
    u8 pad3C[0x8];
    s32 unk44;         /* 0x44 */
    u8 pad48[0x8];
    s32 unk50;         /* 0x50 */
    u16 unk54;         /* 0x54 */
    u16 unk56;         /* 0x56 */
    u8 pad58[0x4];
    u16 unk5C;         /* 0x5C */
    u16 unk5E;         /* 0x5E */
    u16 unk60;         /* 0x60 */
    u16 unk62;         /* 0x62 */
    u16 unk64;         /* 0x64 */
    u8 pad66[0x6];
    u16 unk6C;         /* 0x6C */
    u16 unk6E;         /* 0x6E */
    u8 pad70[0xE];
    u16 unk7E;         /* 0x7E */
    u16 unk80;         /* 0x80 */
    u8 pad82[0xE];
    u16 unk90;         /* 0x90 */
    u16 unk92;         /* 0x92 */
    u8 pad94[0xA];
    u16 unk9E;         /* 0x9E */
    u16 unkA0;         /* 0xA0 */
    u8 padA2[0x2];
    u16 unkA4;         /* 0xA4 */
    u16 unkA6;         /* 0xA6 */
    u8 padA8[0x10];
    u16 unkB8;         /* 0xB8 */
    u8 padBA[0x8];
    u16 unkC2;         /* 0xC2 */
    u16 unkC4;         /* 0xC4 */
    u16 unkC6;         /* 0xC6 */
    u8 padC8[0x4];
    u16 unkCC;         /* 0xCC */
    u16 unkCE;         /* 0xCE */
    u8 padD0[0x2];
    u16 unkD2;         /* 0xD2 */
    u8 padD4[0x6];
    u16 unkDA;         /* 0xDA */
    u8 padDC[0x4];
    s32 unkE0;         /* 0xE0 */
    u8 padE4[0x24];
} AkaoChannel;


/* The driver's channels: 0-23 play the song, 32-55 the sound effects.
 * akao_cmd_song_pop keeps the song's 24 in 24-47 meanwhile. */
extern AkaoChannel D_80096608[56];
/* The song playing ([0]) and the one akao_cmd_song_pop keeps meanwhile. */
extern AkaoSong D_8009A104[2];
/* Songs set aside to come back to (akao_cmd_song_push): two slots. */
extern AkaoChannel D_8007EC10[2][24];
extern AkaoSong D_80083334[2];
/* The sequence of the song being played (func_80029B78 copies it in): a
 * mask of the channels it uses, then where each one's data starts. */
extern u32 D_80083580[];
/* More fields of D_8009A104[0] under names of their own. */
extern s32 D_8009A108;
extern s32 D_8009A10C;
extern s32 D_8009A110;
extern s32 D_8009A114;
extern s32 D_8009A118;
extern s32 D_8009A11C;
extern s32 D_8009A124;
extern s32 D_8009A128;
extern s32 D_8009A12C;
extern s32 D_8009A130;
extern s32 D_8009A134;
extern s32 D_8009A138;
extern s32 D_8009A13C;
extern s32 D_8009A144;
extern s32 D_8009A148;
extern s16 D_8009A14C;
extern s16 D_8009A150;
extern s16 D_8009A152;
extern s16 D_8009A154;
extern s16 D_8009A158;
extern s16 D_8009A15C;
extern s16 D_8009A15E;
extern s16 D_8009A160;
extern s16 D_8009A162;
extern s32 D_8009A120;
extern u16 D_8009A156;
extern u16 D_8009A15A;
/* The sound effects' own state (laid out like a song's), and a field of
 * channel 54, the first menu sound channel, under its own name. */
extern u16 D_80099E0C;
extern u32 D_80099FCC;
extern u32 D_80099FD0;
extern u32 D_80099FD4;
extern u32 D_80099FD8;
extern u32 D_80099FDC;
extern u32 D_80099FEC;
extern u32 D_80099FF0;
extern u32 D_80099FF4;
/* Fields of D_8009A104 the driver reaches under names of their own. */
extern u16 D_8009A14E;    /* [0].id: the song playing */
extern u16 D_8009A1AE;    /* [1].id */

extern s32 D_80062FF8;
extern u32 D_80049C40[];
extern s16 D_80062F44;
extern u16 D_8009C5A8;
extern s32 D_80062F5C;
extern s32 D_80062F2C;
extern u16 *D_80062F74;   /* sound effect -> two sequence offsets, 0xFFFF for none */
extern u8 *D_80062F84;    /* the sound effects' sequences */

void func_80029B78(u8 *sequence, s32 size);
void func_8002A7E8(void);
void func_80029E98(void);
void func_8002B1A8(AkaoChannel *from, AkaoChannel *to, AkaoSong *song_from, AkaoSong *song_to);
void func_8002FF4C(void);
void func_80030038(void);
void func_80030148(void);
void func_80031820(AkaoChannel *ch, s32 arg1);
void func_80029BAC(AkaoChannel *ch, u8 *sequence);
void akao_song_start(void);
void akao_song_resume(u16 slot);
void akao_cmd_song_play(AkaoCommand *cmd);
void akao_cmd_song_push(AkaoCommand *cmd);
void akao_cmd_song_pop(AkaoCommand *cmd);
void akao_sfx_lookup(u8 **first, u8 **second, u16 id);
void akao_sfx_start(u16 pan, u16 channel, u8 *first, u8 *second);
void akao_menu_sfx_start(u8 *first, u8 *second);

extern Pair D_80048D84[];
extern s32 D_80062E24;
extern s32 D_80062E28;
extern s32 D_80062E2C;
extern s32 D_80062F88;
extern s16 D_800707BE[];

void func_80033DAC(s32 a, s32 b);
void func_800144F0(s32 a);
extern s32 D_80062F14;
extern s32 D_80062E30;
extern u8 D_80062DDB;
extern s32 D_80062DEC;
extern s32 D_80062DF8;
extern s8 D_80062EBC;
extern s32 D_80062FC4;
extern s8 D_80062DFC;
extern s32 D_80062E1C;
extern s32 D_80062E20;
extern s32 D_80062FC0;
extern u8 D_8009C739;
extern s32 D_8009D260;
extern s32 D_80071A60;
extern u16 D_800504AE;
extern u8 D_80051638;
extern u8 D_80051648;
extern u8 D_80051649;
extern M2C_UNK D_80051644;
extern s32 D_800518D0;
extern s32 D_80070690;
extern s32 D_80062E94;
extern s32 D_80062E9C;
extern s32 D_8006300C;
extern s16 D_80071A5C;
extern s16 D_800965E8;
extern u16 *D_8005153C;
extern s32 D_80051634;
extern s32 D_80051628;
extern s32 D_8005162C;
extern s32 D_80051A1C;
extern s32 D_80062E18;
M2C_UNK func_80043DD8(M2C_UNK);
M2C_UNK func_8001FA28(M2C_UNK);
M2C_UNK func_80029F44();
M2C_UNK func_8002A43C();
void func_80029A50(void);
M2C_UNK func_80038FEC(M2C_UNK);
M2C_UNK func_80033894();
M2C_UNK func_80034350();
M2C_UNK func_80041F14(M2C_UNK);
M2C_UNK func_800362B8(M2C_UNK);
M2C_UNK func_80042A80();
M2C_UNK func_8003F420();
M2C_UNK func_8003E9DC();
M2C_UNK func_8003EC60();
M2C_UNK func_8003F830();
M2C_UNK func_80040CA8();
extern s32 D_8007E76C;
extern s32 D_8009C6C8;
extern s32 D_8009C6CC;
M2C_UNK func_80042304();
M2C_UNK func_80042394();
M2C_UNK func_8004242C();
extern s8 D_80062DDC;
extern s32 D_80062DE0;
extern s8 D_80062DE5;
extern s32 D_80062EB8;
extern s16 D_80062E08;
M2C_UNK func_8003D120(M2C_UNK, s32);
M2C_UNK func_8003D0F0(M2C_UNK, s32);
M2C_UNK func_8003F398();
s32 func_8003F99C();
M2C_UNK func_80014D9C(M2C_UNK, s32, M2C_UNK);
M2C_UNK func_80015248(M2C_UNK, s32, M2C_UNK);
M2C_UNK func_800429F0(M2C_UNK, M2C_UNK);
M2C_UNK func_800150E4(s32, s32);
s32 func_800151F4(s32);
u8 func_8001F6B4(void);
extern s8 D_80062D71;
void func_800293D0(void);
extern s32 D_80034CF0;
extern s32 D_80034CF4;
extern s32 D_80034CFC;
extern M2C_UNK func_80034E00;
extern M2C_UNK *jtbl_80034D14;
M2C_UNK func_80042AA0();
extern s32 D_8006E11C;
extern void *D_80051534;
s32 func_80040898(void);
extern s32 D_8009C6D4;
extern s32 D_8009FE90;
M2C_UNK func_80048ACC();
M2C_UNK func_80048BEC();
M2C_UNK func_80048C7C();
M2C_UNK func_8001AC9C(s32);
extern s8 D_80062FFC;
extern u8 D_80063020;
M2C_UNK func_8002A748();
M2C_UNK func_8002A798();
M2C_UNK func_80033E34(s32, s32, s32, M2C_UNK);
extern s32 D_80071744;
extern s32 D_800722C8;
extern s32 D_80095DD8;
extern void *D_80062E60;
M2C_UNK func_800443B0(M2C_UNK *);
M2C_UNK func_800444AC(M2C_UNK *);
extern M2C_UNK D_80070700;
extern M2C_UNK D_8007075C;
M2C_UNK func_800211C4(M2C_UNK);
s32 func_80034B44();
M2C_UNK func_801D4CC0();
M2C_UNK func_801D1774();
M2C_UNK func_801D2D74();
M2C_UNK func_801D2E84();
M2C_UNK func_801D3228();
M2C_UNK func_801D027C();
extern M2C_UNK (*D_80071A84)();
M2C_UNK func_8003DFD4(M2C_UNK, M2C_UNK);
extern s32 D_8006E0F4;
void func_8003D0C0(void);
s32 func_80042168(s32);
M2C_UNK func_80042AF0();
M2C_UNK func_80042B00();
M2C_UNK func_80042BA0(M2C_UNK);
M2C_UNK func_80048ABC();
M2C_UNK func_80014D58(M2C_UNK, s32, M2C_UNK);
s32 func_80044FA0(M2C_UNK);
s32 func_8002DA7C(s32);
extern s16 D_8009A000;
extern s32 D_8009A004;
extern s32 D_8009A008;
void func_800293F4(void);
M2C_UNK func_80038F04(s32, M2C_UNK);
M2C_UNK func_80037BE0(s32, M2C_UNK);
M2C_UNK func_8003408C();
M2C_UNK func_8003DD18(M2C_UNK);
void func_8003DD84(void);
M2C_UNK func_80033CB8(M2C_UNK, s32, s32, s32, s32);
void func_800110B8(void);
void func_80011920(void);
s32 func_800144D8(s32 i);
void func_80014510(s32 i);
void func_80014540(void);
void func_80014608(void);
void func_800148A0(void);
void func_800149E0(void);
s32 func_80014A38(u32 x);
void func_80014B54(void);
void func_80014C70(void);
void func_80014DD0(s32 arg0, s32 arg1, M2C_UNK arg2);
void func_8001521C(s32 arg0);
void func_800155A4(s32 arg0);
void func_80015654(s32 a);
void func_80015B44(s32 arg0);
s32 func_80015B50(void);
s32 func_80015B88(void);
s32 func_80016320(void *arg0);
void func_80019E4C(void);
void func_8001A384(s32 arg0);
void func_8001C3C4(void);
void func_8001C484(s32 arg0);
void func_8001C58C(void);
void func_8001DE0C(void *arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4);
void func_8001DE24(void *arg0, s32 arg1, s32 arg2);
void func_8001DE40(void *arg0, void *arg1);
void func_8001F6AC(void);
void func_8001F6C0(s32 arg0, s8 arg1);
void func_8001FAF0(void);
void func_800211B8(s32 arg0);
void func_80021258(s32 arg0);
void func_80021280(s32 arg0);
s32 func_80023050(void);
void func_80023AC4(void);
void func_80024A04(void);
void func_80024E5C(void);
void func_80024E94(void);
void func_80024ECC(void);
void func_80024F04(void);
void func_80025008(void);
void func_800250B4(void);
void func_80025360(void);
void func_800254D8(void);
void func_80025648(void);
void func_80025650(void);
u8 func_80025658(void);
void func_800257C4(void);
s32 func_80025B7C(void);
void func_80026034(void);
void func_80026408(s32 arg0);
void func_80026A00(s32 arg0);
void func_80026A0C(void);
void func_80026A20(void);
void func_80026B5C(void);
void func_80026B64(s8 arg0);
void func_80029424(s32 arg0, M2C_UNK arg1);
void func_80029464(s32 arg0, M2C_UNK arg1);
void func_8002C7A8(void);
void func_8002C7C8(void);
void func_8002C7E8(void);
void func_8002C81C(void);
void func_8002C850(void);
void func_8002CCBC(void);
void func_8002CCCC(void);
void func_8002CF78(void);
void func_8002CF98(void);
void func_8002CFA0(void);
void func_80032078(void *arg0);
void func_80032094(void *arg0);
void func_800320AC(void *arg0);
void func_800324D8(void *arg0);
void func_80032500(void *arg0);
void func_8003257C(void *arg0);
void func_800325B8(void *arg0);
void func_800325C0(void *arg0);
void func_800325E8(void *arg0);
void func_800327E0(void *arg0);
void func_800328D4(void *arg0);
void func_80032968(void *arg0);
void func_80032A04(void *arg0);
void func_80032A98(void *arg0);
void func_80032D44(void *arg0);
void func_80032D50(void);
void func_80032D58(void *arg0);
void func_80032D64(void);
void func_80033224(void *arg0);
void func_80033534(void *arg0);
void func_80033788(void *arg0);
void func_8003379C(void *arg0);
void func_800337B0(void *arg0);
void func_800337C4(void *arg0);
void func_80033A70(void);
void func_80033BE0(void);
void func_800343F0(void);
s32 func_80034410(void);
void func_80034420(void);
void func_80034428(void);
void func_80034430(void);
void func_80034444(void);
void func_80034A58(void);
void func_80034D2C(s32 arg0, s32 arg1);
void func_80034F3C(void);
void func_80036298(void);
void func_80036FD8(s32 arg0);
void func_80038C48(s32 arg0);
s32 func_8003CE8C(void);
void func_8003CEBC(void);
void func_8003D150(s32 arg0);
void func_8003D184(void);
void func_8003D1B4(void);
void func_8003D1E4(void);
u16 func_8003D214(void);
u16 func_8003D224(void);
void func_8003DBA0(s32 arg0, s32 arg1);
void func_8003DC60(void);
void func_8003DC88(void);
void func_8003DCB0(void);
u8 func_8003DCD8(void);
u8 func_8003DCE8(void);
u8 func_8003DCF8(void);
M2C_UNK *func_8003DD08(void);
s32 func_8003DDA4(s32 arg0);
void func_8003DE2C(void);
void func_8003DE4C(void);
s32 func_8003DE6C(s32 arg0);
s32 func_8003DE84(s32 arg0);
s32 func_8003E244(void);
s32 func_8003E268(void);
void func_8003E28C(s32 arg0);
void func_8003E2B0(void);
void func_8003FA9C(s32 arg0);
void func_80040628(void);
void func_80040C88(s32 arg0, s32 arg1, s32 arg2);
s32 func_80041EFC(s32 arg0);
u16 func_80042038(u16 *arg0);
void func_800420C0(void);
void func_800420E0(void);
void func_80042100(void);
void func_80042120(s32 arg0);
void func_80042144(s32 arg0);
void func_8004493C(void *arg0, M2C_UNK arg1);
void func_80044A40(void *arg0, s32 arg1, s32 arg2);
s32 func_80046634(s32 arg0, s32 arg1);
s32 func_8004675C(s32 *arg0);
s32 func_80046778(s32 *arg0);
void func_8004680C(s32 *arg0, s32 arg1);
void func_80046830(s32 *arg0);
void func_80046848(void *arg0, s32 arg1);
void func_80046870(void *arg0, s32 arg1);
void func_80046898(void *arg0);
void func_800468AC(void *arg0);
void func_800468C0(void *arg0);
void func_800468D4(void *arg0);
void func_800468E8(void *arg0);
void func_800468FC(void *arg0);
void func_80046910(void *arg0);
void func_80046924(void *arg0);
void func_80046938(void *arg0);
void func_8004694C(void *arg0);
void func_80046960(void *arg0);
void func_80046974(void *arg0);
void func_80046988(void *arg0);
void func_8004699C(void *arg0);
void func_800469B0(void *arg0);
void func_800469C4(void *arg0);
void func_800469D8(void *arg0);
void func_800469EC(void *arg0);
void func_80046A0C(void *arg0);
void func_80046A2C(void *arg0);
void func_80046A4C(void *arg0);
void func_80046A6C(void *arg0);
void func_80046A80(void *arg0);
s32 func_80046CFC(s32 arg0);
void func_80048A44(void);
void func_80048A7C(void);
s32 func_80043928(void);
extern s32 D_80062BB4;
u8 func_80043CC0(void);
extern u8 D_80062C00;
u8 func_80043CD0(void);
extern u8 D_80062C02;
void func_8002C8C4(void *arg0);
s32 func_80043910(s32 arg0);
s32 func_800450E0(void);
extern s32 *D_80062CD4;
void func_8002CC18(void *arg0);
extern s16 D_80062F70;
s32 func_800459D0(s32 arg0);
extern s32 *D_80062CD0;
u32 func_80044908(void);
extern void *D_80062BF8;
void func_800462B0(void);
s32 func_8003CEDC(M2C_UNK);
extern s32 D_80062D18;
extern s32 D_80062D1C;
void func_8004671C(s32 arg0);
extern M2C_UNK D_80010EC8;
extern M2C_UNK (*D_80062BFC)(M2C_UNK *, s32, u32);
void func_8001FA68(s32 arg0);
void func_8001FAAC(s32 arg0);
void func_80024DD4(s32 arg0);
M2C_UNK func_801D1A6C(s32);
void func_80024E18(s32 arg0);
M2C_UNK func_801D4118(s32);
void func_80024F3C(s32 arg0);
M2C_UNK func_801D2F00(s32);
void func_80024F80(s32 arg0);
M2C_UNK func_801D3138(s32);
void func_80024FC4(s32 arg0);
M2C_UNK func_801D3018(s32);
void func_800250EC(s32 arg0);
M2C_UNK func_801D05C4(s32);
void func_80025130(s32 arg0);
M2C_UNK func_801D0704(s32);
void func_8002B668(void *arg0);
M2C_UNK func_8002A510(M2C_UNK, M2C_UNK);
void func_80033588(u8 **arg0, void *arg1);
void func_80034048(void);
extern s32 D_80071A6C;
extern s32 D_80071A80;
void func_8003447C(void);
extern s32 D_800698EC;
extern M2C_UNK D_80071A68;
void func_800345BC(void);
void func_800347B4(void);
s32 func_80038C04(s32 arg0);
extern s32 D_8004AB30;
void func_800449FC(void *arg0, void *arg1);
s32 func_80044F58(s16, s16);
void func_800145BC(M2C_UNK (*arg0)());
void func_80014934(void);
M2C_UNK func_80014578(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80015C3C(M2C_UNK, M2C_UNK *, M2C_UNK);
extern M2C_UNK D_8009C738;
void func_8001A980(s32 arg0, s32 arg1, M2C_UNK arg2);
M2C_UNK func_8001A9CC(s32, M2C_UNK);
M2C_UNK func_8001AB1C(s32, M2C_UNK);
void func_8002120C(s32 arg0);
extern s32 D_80062DD0;
extern s32 D_80062DD4;
void func_80024D88(s32 arg0);
M2C_UNK func_801D131C(s32);
void func_80026090(void);
M2C_UNK func_801D11A8();
extern s32 D_80062F90;
void func_80034104(void);
M2C_UNK func_8003E100(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800140A4(void);
M2C_UNK func_80013C9C();
M2C_UNK func_8004433C(s32);
extern s32 D_8019D5E8;
extern s32 D_8019DAA0;
void func_8002B8B4(void *arg0);
void func_8003252C(void *arg0);
void func_800335D8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2);
M2C_UNK func_80032E6C();
M2C_UNK func_80032ED0(s32, M2C_UNK, M2C_UNK);
s32 func_80033DE4(s32 arg0);
s32 func_8003DE9C(M2C_UNK, M2C_UNK *, M2C_UNK);
void func_800387FC(void *arg0);
extern s32 D_8004A6A4;
extern u16 D_8004A6A8;
extern u16 D_8004A6AA;
extern s32 D_8004A6AC;
extern s32 D_8004A6B0;
void func_8001A174(s32 arg0, s32 arg1, M2C_UNK arg2);
M2C_UNK func_8001A1C8(s32, M2C_UNK);
M2C_UNK func_8001A280(s32, M2C_UNK);
void func_8002B904(void *arg0);
void func_8002B958(void *arg0);
void func_8002BA08(void *arg0);
void func_80031E98(void *arg0, void *arg1);
extern s32 D_80062F04;
M2C_UNK *func_8003D7D0(void);
M2C_UNK func_8003D8CC(M2C_UNK *, M2C_UNK);
extern M2C_UNK D_80051548;
extern s32 D_80051568;
extern s32 *D_8005156C;
extern M2C_UNK func_8003D828;
extern M2C_UNK func_8003D8A0;
void func_80044A68(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3, s32 arg4);
s32 func_80044D64(M2C_UNK, M2C_UNK, s32);
void func_8002B9AC(void *arg0);
void func_80032C8C(void *arg0, void *arg1, s32 arg2);
void func_800346F8(void);
M2C_UNK func_80034CAC(M2C_UNK);
s32 func_80041D28(s32, s32, M2C_UNK);
void func_80014980(void *arg0);
s32 func_80044000(void *arg0, void *arg1);
void func_80026448(void *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10, s32 arg11, s32 arg12, u16 arg13);
void func_8002B5A8(AkaoCommand *arg0);
M2C_UNK func_8002AFB8();
extern u16 D_80062FC8;
void func_8002B608(AkaoCommand *arg0);
void func_80034754(void);
s32 func_80041E30(M2C_UNK, M2C_UNK);
s32 func_80040B84(M2C_UNK, s32);
extern s32 D_80071740;
extern s16 D_80071C10;
extern s32 D_80075CFC;
extern s32 D_80095D80;
extern s32 D_8009C548;
extern s32 D_8009C54C;
extern s32 D_8009C550;
void func_800442DC(void *arg0);
s16 func_800135C0(s32 arg0, s32 arg1, s16 arg2, s16 arg3);
void func_80035D64(void);
s32 func_80040594(s32 arg0);
extern u16 D_80095DC4;
extern s32 D_80071A68;
M2C_UNK func_80043E44(M2C_UNK *, void *);
extern M2C_UNK D_80010DCC;
void func_80044064(void *arg0, M2C_UNK arg1);
extern s32 D_80010DD8;
void func_8001171C(void);
M2C_UNK func_80039EDC();
M2C_UNK func_80043938(M2C_UNK);
M2C_UNK func_80043BA8(M2C_UNK);
M2C_UNK func_80043D3C(M2C_UNK);
extern s16 D_80095DD4;
extern M2C_UNK func_8001155C;
void func_8001A440(void);
M2C_UNK func_8001B834(M2C_UNK);
s32 func_80033E74(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 D_800698E8;
extern M2C_UNK D_800698F0;
void func_80032BB4(void *arg0, void *arg1, s32 arg2);
s32 func_800404F4(s32 arg0, M2C_UNK arg1, s32 arg2);
M2C_UNK func_8003E2D0(M2C_UNK, s32 *);
void func_8001A4A8(void);
M2C_UNK func_8001BCE8(s32);
extern u8 D_80062E8C;
void func_80033B70(void);
M2C_UNK func_80034F5C();
s32 func_8003DBD0();
extern s32 D_80071A64;
void func_80011274(void);
M2C_UNK func_80029818(M2C_UNK, M2C_UNK);
extern s32 D_80048D14;
extern s32 D_80048D18;
extern s32 D_80048D1C;
extern s32 D_80048D20;
void func_80032ABC(void *arg0, void *arg1, s32 arg2);
s32 func_8003884C(void *arg0);
extern void *D_8004AAF4;
void func_800363B0(void);
s32 func_80042A00(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_80042A40(s32);
extern s32 D_8004A688;
extern s32 D_8004AAF0;
extern M2C_UNK func_8003688C;
void func_80033708(void *arg0, M2C_UNK arg1, M2C_UNK arg2);
M2C_UNK func_80032B30();
M2C_UNK func_80032C20(void *, M2C_UNK, M2C_UNK);
M2C_UNK func_80032CE8(void *, M2C_UNK, M2C_UNK);
void func_800348F4(void);
extern s32 D_8006E0F8;
s32 func_8003E3D4(void *arg0);
void func_8002B6AC(void *arg0);
s32 func_80033F40(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_80033FC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80044978(void *arg0, void *arg1);
s32 func_80044DC0(s16, s16);
s32 func_80044E8C(s16, s16);
void func_800299C8(void);
M2C_UNK func_80038A84(M2C_UNK);
M2C_UNK func_80038C6C(M2C_UNK, M2C_UNK);
s32 func_80042A10(s32);
s32 func_80042A50(s32);
M2C_UNK func_80042AE0(M2C_UNK, M2C_UNK);
s32 func_80042CCC(s32);
extern s32 D_80062E00;
void func_80040A40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 D_80071C14;
extern s32 D_80074EA0;
extern s32 D_800756E4;
extern s32 D_8007E764;
extern s32 D_80081DC0;
extern s32 D_8009C6C0;
void func_8002D410(void);
M2C_UNK func_80038BC4(M2C_UNK);
extern s32 D_80062F00;
extern s32 D_80063004;
extern M2C_UNK func_8002D530;
void func_8002D4A0(void);
extern M2C_UNK func_8002D7A0;
extern s32 D_80071C18;
extern M2C_UNK func_80040950;
extern s32 D_80097768;
extern s32 D_80097870;
s32 func_80023788(s32 arg0);
extern s32 D_80049474;
extern s32 D_80049478;
void func_80011938(void);
M2C_UNK func_8002988C(M2C_UNK, M2C_UNK);
M2C_UNK func_80029998(M2C_UNK);
extern s32 D_80048CFC;
extern s32 D_80048D00;
extern s32 D_80048D04;
extern s32 D_80048D08;
extern s32 D_80048D0C;
extern s32 D_80048D10;
void func_8002B730(void *arg0);

#endif /* MAIN_DECLS_H */
