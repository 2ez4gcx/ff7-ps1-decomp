#include "common.h"
#include "main/decls.h"

void func_80029A50(void) {
    func_80038FEC(0);
    func_80038A84(0);
    func_80038C04(0);
    func_80038C6C(0, D_80062F00);
    if (D_80062F00 & 0x10000) {
        D_80097768 = 0x1FF93;
    }
    if (D_80062F00 & 0x20000) {
        D_80097870 = 0x1FF93;
    }
    D_80062F00 = 0;
    func_80030038();
    func_80030148();
    func_8002FF4C();
}

void func_80029AF0(s32 arg0) {
    s32 *p;

    func_80029A50();
    p = &D_8009C564;
    func_800387FC(p);
    if (D_8009C568 != arg0) {
        D_8009A140 = arg0;
        func_80037C40(0);
        D_8009C568 = arg0 | 0x100;
        *p = 1;
        func_80037E1C(p);
        func_80037C40(1);
    }
}

void func_80029B78(u8 *sequence, s32 size) {
    u32 *src;
    u32 *dst;
    u32 n;

    src = (u32 *)sequence;
    n = (u32)size >> 2;
    dst = D_80083580;
    while (n != 0) {
        n--;
        *dst++ = *src++;
    }
}

void func_80029BAC(AkaoChannel *ch, u8 *sequence) {
    ch->addr = sequence;
    ch->unk2C = 0x78;
    func_80031820(ch, 5);
    M2C_FIELD(ch, s16 *, 0x66) = 2;
    ch->unkCE = 0;
    ch->unkCC = 0;
    ch->unk6C = 0;
    ch->unk34 = 0;
    ch->unkD2 = 0;
    ch->unkC4 = 0;
    ch->unkC2 = 0;
    ch->unk64 = 0;
    ch->unk44 = 0x32000000;
    ch->unk5C = 0;
    ch->unk38 = 0;
    ch->unkB8 = 0;
    ch->unk6E = 0;
    ch->unkDA = 0;
    ch->unk9E = 0;
    ch->unk90 = 0;
    ch->unk7E = 0;
    ch->unkA0 = 0;
    ch->unk92 = 0;
    ch->unk80 = 0;
    ch->unkA6 = 0;
    ch->unkA4 = 0;
}

/* Start the song whose sequence is in D_80083580: set up the channels it
 * uses and the song's own state. */
void akao_song_start(void)
{
    u32 *seq;
    AkaoChannel *ch;
    u32 mask;
    u32 bit;
    s32 active;
    u16 offset;

    seq = D_80083580;
    mask = *seq++ & 0xFFFFFF;
    ch = D_80096608;
    D_8009A114 |= 0xFFFFFF;
    D_8009A108 = mask;
    bit = 1;
    while (mask != 0) {
        if (mask & bit) {
            offset = *(u16 *)seq;
            seq = (u32 *)((u16 *)seq + 1);
            mask ^= bit;
            ch->addr = (u8 *)seq + offset;
            ch->unk56 = 0x103;
            ch->unk2C = 0x7F;
            func_80031820(ch, 0x14);
            ch->unk44 = 0x3FFF0000;
            ch->unkC6 = 0x4000;
            ch->unk60 = 0x4000;
            ch->start = (u8 *)D_80083580;
            ch->unkCE = 0;
            ch->unkCC = 0;
            ch->unk34 = 0;
            ch->unkD2 = 0;
            ch->unk64 = 0;
            ch->unk6C = 0;
            ch->unkC4 = 0;
            ch->unkC2 = 0;
            ch->unk5E = 0;
            ch->unk5C = 0;
            ch->unk62 = 0;
            ch->unk6C = 0;
            ch->unk38 = 0;
            ch->unkB8 = 0;
            ch->unk6E = 0;
            ch->unkDA = 0;
            ch->unk9E = 0;
            ch->unk90 = 0;
            ch->unk7E = 0;
            ch->unkA0 = 0;
            ch->unk92 = 0;
            ch->unk80 = 0;
            ch->unkA6 = 0;
            ch->unkA4 = 0;
        }
        ch++;
        bit <<= 1;
    }
    D_8009A11C = 0xFFFF0000;
    D_8009A124 = 1;
    D_8009A14C = 0;
    D_8009A144 = 0;
    D_8009A154 = 0;
    D_8009A148 = 0;
    D_8009A13C = 0;
    D_8009A160 = 0;
    D_8009A15E = 0;
    D_8009A15C = 0;
    D_8009A162 = 0;
    D_8009A130 = 0;
    D_8009A134 = 0;
    D_8009A138 = 0;
    D_8009A152 = 0;
    D_8009A150 = 0;
    D_8009A158 = 0;
    D_8009A110 = 0;
    D_8009A10C = 0;
    D_8009A12C = 0;
    D_8009A128 = 0;
    if (D_80062FF8 & 1) {
        active = D_8009A108;
        D_8009A108 = 0;
        D_8009A118 = active;
    }
    func_8002FF4C();
    func_80030038();
    func_80030148();
}

void func_80029E98(void) {
    AkaoChannel *ch;
    s32 temp_v0;
    s32 temp_v1;
    s32 mask;
    s32 bit;

    mask = D_8009A108;
    if (mask != 0) {
        ch = D_80096608;
        bit = 1;
        temp_v0 = D_8009A128;
        temp_v1 = D_8009A12C;
        D_8009A12C = 0;
        D_8009A128 = 0;
        D_8009A110 = 0;
        D_8009A10C = 0;
        mask |= temp_v0 | temp_v1;
        D_8009A108 = mask;
        D_8009A114 |= mask;
        do {
            if (mask & bit) {
                mask ^= bit;
                ch->unk56 = 0x204;
                ch->addr = (u8 *) D_80049C40;
            }
            bit *= 2;
            ch++;
        } while (mask != 0);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80029F44);

/* Start a sound effect on channels `channel` and `channel` + 1 (32 and up),
 * one for each sequence it has (akao_sfx_lookup); `pan` 0-127. */
void akao_sfx_start(u16 pan, u16 channel, u8 *first, u8 *second)
{
    AkaoChannel *ch;
    u32 voices;
    u32 active;
    s32 shift;
    u32 *playing;

    voices = 0;
    pan = (pan & 0x7F) << 8;
    ch = &D_80096608[channel];
    ch[0].unk56 = 0x101;
    ch[1].unk56 = 0x101;
    ch[0].addr = (u8 *)D_80049C40;
    ch[1].addr = (u8 *)D_80049C40;
    ch[0].unk54 = 1;
    ch[1].unk54 = 1;
    ch[0].unk50 = -1;
    ch[1].unk50 = -1;
    if (first != NULL) {
        voices = 1;
        func_80029BAC(ch, first);
        ch->unk60 = pan;
        ch->unk62 = 0;
    }
    ch++;
    if (second != NULL) {
        voices |= 2;
        func_80029BAC(ch, second);
        ch->unk60 = pan;
        ch->unk62 = 0;
    }
    shift = channel - 0x20;
    voices <<= shift;
    playing = &D_80099FCC;
    active = voices | *playing;
    voices = (3 << shift) & active;
    *playing = active;
    D_80099FD8 |= voices;
    voices = ~voices;
    D_80099FD0 &= voices;
    D_80099FD4 &= voices;
    D_80099FEC &= voices;
    D_80099FF0 &= voices;
    D_80099FF4 &= voices;
    if (D_80062FF8 & 2) {
        voices = active;
        if (D_80099E0C == 2) {
            *playing = voices & 0xC00000;
            voices &= 0xFF3FFFFF;
        } else {
            *playing = 0;
        }
        D_80099FDC |= voices;
    }
    func_8002FF4C();
    func_80030038();
    func_80030148();
}

/* A menu sound: channels 54 and 55. */
#ifndef NON_MATCHING
INCLUDE_ASM("../asm/us/main/nonmatchings/akao", akao_menu_sfx_start);
#else
/* Matches but for four instructions: GCC loads 0x101 before the channel
 * pointer, the game after it. */
void akao_menu_sfx_start(u8 *first, u8 *second)
{
    AkaoChannel *ch;
    u32 voices;
    u32 *playing;

    ch = &D_80096608[54];
    ch[0].unk56 = 0x101;
    ch[1].unk56 = 0x101;
    ch[0].addr = (u8 *)D_80049C40;
    ch[1].addr = (u8 *)D_80049C40;
    ch[0].unk54 = 2;
    ch[1].unk54 = 2;
    ch[0].unk50 = -1;
    ch[1].unk50 = -1;
    voices = 0;
    if (first != NULL) {
        voices = 1;
        func_80029BAC(&ch[0], first);
        ch[0].unk60 = 0x4000;
        ch[0].unk62 = 0;
    }
    if (second != NULL) {
        voices |= 2;
        func_80029BAC(&ch[1], second);
        ch[1].unk60 = 0x4000;
        ch[1].unk62 = 0;
    }
    playing = &D_80099FCC;
    voices <<= 22;
    *playing |= voices;
    voices = 0xC00000;
    D_80099FD8 |= voices;
    voices = ~voices;
    D_80099FD0 &= voices;
    D_80099FD4 &= voices;
    D_80099FEC &= voices;
    D_80099FF0 &= voices;
    D_80099FF4 &= voices;
    func_8002FF4C();
    func_80030038();
    func_80030148();
    D_80099FDC &= voices;
}
#endif

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002A43C);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002A510);

/* The two sequences of sound effect `id` (NULL where it has none). */
void akao_sfx_lookup(u8 **first, u8 **second, u16 id)
{
    u16 index = (id & 0x3FF) * 2;
    u16 offset;
    u8 *seq;

    offset = D_80062F74[index];
    if (offset != 0xFFFF) {
        seq = D_80062F84 + offset;
    } else {
        seq = 0;
    }
    index++;
    *first = seq;
    offset = D_80062F74[index];
    if (offset != 0xFFFF) {
        seq = D_80062F84 + offset;
    } else {
        seq = 0;
    }
    *second = seq;
}

void func_8002A748(void) {
    AkaoChannel *ch;
    s32 bit;
    s32 mask;

    ch = D_80096608;
    mask = D_8009A108;
    if (mask != 0) {
        bit = 1;
        do {
            if (mask & bit) {
                mask ^= bit;
                ch->unkE0 |= 3;
            }
            ch++;
            bit <<= 1;
        } while (mask != 0);
    }
}

void func_8002A798(void) {
    AkaoChannel *ch;
    u32 mask;
    u32 bit;

    mask = D_80099FCC;
    ch = &D_80096608[48];
    if (mask != 0) {
        bit = 0x10000;
        do {
            if (mask & bit) {
                mask ^= bit;
                ch->unkE0 |= 3;
            }
            ch++;
            bit <<= 1;
        } while (mask != 0);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002A7E8);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002A958);

/* Carry on with the song slot `slot` kept (akao_cmd_song_push): its state
 * and channels come back, the channels it does not use are silenced. */
void akao_song_resume(u16 slot)
{
    u32 *from;
    u32 *to;
    u16 n;
    AkaoChannel *ch;
    u32 mask;
    u32 bit;
    s32 active;

    D_8009A104[0].active = D_80083334[slot].active;
    D_8009A104[0].unk8 = D_80083334[slot].unk8;
    D_8009A104[0].unkC = D_80083334[slot].unkC;
    D_8009A104[0].unk18 = D_80083334[slot].unk18;
    D_8009A104[0].unk1C = D_80083334[slot].unk1C;
    D_8009A104[0].unk48 = D_80083334[slot].unk48;
    D_8009A104[0].unk20 = D_80083334[slot].unk20;
    D_8009A104[0].unk24 = D_80083334[slot].unk24;
    D_8009A104[0].unk28 = D_80083334[slot].unk28;
    D_8009A104[0].id = D_80083334[slot].id;
    D_8009A104[0].unk4C = D_80083334[slot].unk4C;
    D_8009A104[0].unk4E = D_80083334[slot].unk4E;
    D_8009A104[0].unk40 = D_80083334[slot].unk40;
    D_8009A104[0].unk44 = D_80083334[slot].unk44;
    D_8009A104[0].unk50 = D_80083334[slot].unk50;
    D_8009A104[0].unk52 = D_80083334[slot].unk52;
    D_8009A104[0].unk2C = D_80083334[slot].unk2C;
    D_8009A104[0].unk30 = D_80083334[slot].unk30;
    D_8009A104[0].unk34 = D_80083334[slot].unk34;
    D_8009A104[0].unk54 = D_80083334[slot].unk54;
    D_8009A104[0].unk38 = D_80083334[slot].unk38;
    D_8009A104[0].unk56 = D_80083334[slot].unk56;
    D_8009A104[0].unk58 = D_80083334[slot].unk58;
    D_8009A104[0].unk5A = D_80083334[slot].unk5A;
    D_8009A104[0].unk5C = D_80083334[slot].unk5C - 2;
    D_8009A104[0].unk5E = D_80083334[slot].unk5E;
    D_8009A104[0].unk38 |= 0x80;
    from = (u32 *)D_8007EC10[1];
    if (slot == 0) {
        from = (u32 *)D_8007EC10[0];
    }
    to = (u32 *)D_80096608;
    n = 0x630;
    do {
        n--;
        *to++ = *from++;
    } while (n);
    mask = D_8009A108;
    if (mask != 0) {
        ch = D_80096608;
        bit = 1;
        for (n = 24; n != 0; n--, ch++, bit <<= 1) {
            if (!(mask & bit)) {
                ch->unk56 = 0x204;
                ch->addr = (u8 *)D_80049C40;
            }
        }
    }
    mask |= D_8009A128;
    D_8009A114 = ~D_8009A10C & 0xFFFFFF;
    ch = D_80096608;
    bit = 1;
    while (mask != 0) {
        if (mask & bit) {
            mask ^= bit;
            ch->unk56 += 0x202;
            ch->unkE0 |= 0x1FF93;
        }
        ch++;
        bit <<= 1;
    }
    func_8002FF4C();
    func_80030038();
    func_80030148();
    if (D_80062F44 == 0 && D_8009C5A8 == 0) {
        D_80062F2C = (D_80062F5C - 0xA0000) / 60;
        D_80062F44 = 60;
        D_80062F5C = 0xA0000;
    }
    D_80083334[slot].id = 0;
    if (D_80062FF8 & 1) {
        active = D_8009A108;
        D_8009A108 = 0;
        D_8009A118 = active;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002AFB8);

void func_8002B1A8(AkaoChannel *from, AkaoChannel *to, AkaoSong *song_from, AkaoSong *song_to) {
    s32 *src = (s32 *)from;
    s32 *dst = (s32 *)to;
    s32 *src2 = (s32 *)song_from;
    s32 *dst2 = (s32 *)song_to;
    u16 n;

    n = 0x630;
    do {
        n--;
        *dst++ = *src++;
    } while (n);
    n = 0x18;
    do {
        n--;
        *dst2++ = *src2++;
    } while (n);
}

/* Command 0x10: load a song and play it, or carry on with it where a slot kept it. */
void akao_cmd_song_play(AkaoCommand *cmd)
{
    func_80029B78(cmd->sequence, cmd->size);
    if (D_8009A14E == 0xE) {
        func_8002A7E8();
        func_8002B1A8(D_80096608, D_8007EC10[1], &D_8009A104[0], &D_80083334[1]);
    }
    func_80029E98();
    if (D_80083334[0].id != 0 && D_80083334[0].id == cmd->song) {
        akao_song_resume(0);
    } else if (D_80083334[1].id != 0 && D_80083334[1].id == cmd->song) {
        akao_song_resume(1);
    } else {
        akao_song_start();
    }
    D_8009A14E = cmd->song;
}

/* Command 0x14: keep the song playing in a slot (1 for song 0xE, else 0), then play a new one. */
void akao_cmd_song_push(AkaoCommand *cmd)
{
    AkaoSong *song;

    func_80029B78(cmd->sequence, cmd->size);
    func_8002A7E8();
    song = &D_8009A104[0];
    if (D_8009A14E != 0) {
        if (D_8009A14E == 0xE) {
            func_8002B1A8(D_80096608, D_8007EC10[1], song, &D_80083334[1]);
        } else {
            func_8002B1A8(D_80096608, D_8007EC10[0], song, &D_80083334[0]);
        }
    }
    func_80029E98();
    akao_song_start();
    D_8009A14E = cmd->song;
}

/* Command 0x15: bring back the song a slot kept, keeping the one playing in its place. */
void akao_cmd_song_pop(AkaoCommand *cmd)
{
    AkaoSong *song;

    D_80062FF8 &= ~0x100;
    func_80029B78(cmd->sequence, cmd->size);
    func_8002A7E8();
    if (D_80083334[0].id == cmd->song) {
        func_8002B1A8(D_80096608, &D_80096608[24], &D_8009A104[0], &D_8009A104[1]);
        func_80029E98();
        akao_song_resume(0);
        if (D_8009A1AE == 0xE) {
            func_8002B1A8(&D_80096608[24], D_8007EC10[1], &D_8009A104[1], &D_80083334[1]);
        } else {
            func_8002B1A8(&D_80096608[24], D_8007EC10[0], &D_8009A104[1], &D_80083334[0]);
        }
    } else if (D_80083334[1].id == cmd->song) {
        func_8002B1A8(D_80096608, &D_80096608[24], &D_8009A104[0], &D_8009A104[1]);
        func_80029E98();
        akao_song_resume(1);
        if (D_8009A1AE == 0xE) {
            func_8002B1A8(&D_80096608[24], D_8007EC10[1], &D_8009A104[1], &D_80083334[1]);
        } else {
            func_8002B1A8(&D_80096608[24], D_8007EC10[0], &D_8009A104[1], &D_80083334[0]);
        }
    } else {
        song = &D_8009A104[0];
        if (D_8009A14E != 0) {
            if (D_8009A14E == 0xE) {
                func_8002B1A8(D_80096608, D_8007EC10[1], song, &D_80083334[1]);
            } else {
                func_8002B1A8(D_80096608, D_8007EC10[0], song, &D_80083334[0]);
            }
        }
        func_80029E98();
        akao_song_start();
    }
    D_8009A104[1].unk28 = 0;
    D_8009A104[1].unk24 = 0;
    D_8009A104[1].active = 0;
    D_8009A14E = cmd->song;
}

void func_8002B5A8(AkaoCommand *arg0) {
    u16 var_v1;

    if (D_8009A14E != 0) {
        var_v1 = 0x10;
        if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
            var_v1 = (u16) M2C_FIELD(arg0, s32 *, 0x10);
        }
        D_80062FC8 = var_v1;
        func_8002AFB8();
    }
    akao_cmd_song_play(arg0);
}

void func_8002B608(AkaoCommand *arg0) {
    u16 var_v1;

    if (D_8009A14E != 0) {
        var_v1 = 0x10;
        if (M2C_FIELD(arg0, s32 *, 0x10) != 0) {
            var_v1 = (u16) M2C_FIELD(arg0, s32 *, 0x10);
        }
        D_80062FC8 = var_v1;
        func_8002AFB8();
    }
    akao_cmd_song_push(arg0);
}

void func_8002B668(void *arg0) {
    func_8002A510(4, 1);
    akao_sfx_start(0x40U, 0x34U, M2C_FIELD(arg0, u8 **, 4), M2C_FIELD(arg0, u8 **, 8));
}

void func_8002B6AC(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(4, 2);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x32U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0xC));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x34U, sp10, sp14);
}

void func_8002B730(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(4, 3);
    func_80029A50();
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x30U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0xC));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x32U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0x10));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x34U, sp10, sp14);
}

void func_8002B7E0(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(6, 4);
    func_80029A50();
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x30U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0xC));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x32U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0x10));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x34U, sp10, sp14);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 0x14));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x36U, sp10, sp14);
}

void func_8002B8B4(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(6, 1);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 4));
    akao_menu_sfx_start(sp10, sp14);
}

void func_8002B904(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(4, 1);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x34U, sp10, sp14);
}

void func_8002B958(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(2, 1);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x32U, sp10, sp14);
}

void func_8002B9AC(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(0, 1);
    func_80029A50();
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x30U, sp10, sp14);
}

void func_8002BA08(void *arg0) {
    u8 *sp10;
    u8 *sp14;

    func_8002A510(6, 1);
    akao_sfx_lookup(&sp10, &sp14, M2C_FIELD(arg0, u16 *, 8));
    akao_sfx_start(M2C_FIELD(arg0, u16 *, 4), 0x36U, sp10, sp14);
}

void func_8002BA5C(void *arg0) {
    D_80062F44 = 0;
    D_80062F5C = (M2C_SFIELD(arg0, s32 *, 4) & 0x7F) << 0x10;
    func_8002A748();
}

void func_8002BA98(void *arg0) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = M2C_SFIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    D_80062F44 = (s16) var_a1;
    D_80062F2C = (s32) (((M2C_SFIELD(arg0, s32 *, 8) & 0x7F) << 0x10) - D_80062F5C) / var_a1;
    func_8002A748();
}

void func_8002BB20(void *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s32 end;
    s32 start;

    temp_v0 = M2C_SFIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    end = (M2C_SFIELD(arg0, s32 *, 0xC) & 0x7F) << 0x10;
    start = (M2C_SFIELD(arg0, s32 *, 8) & 0x7F) << 0x10;
    D_80062F44 = (s16) var_a1;
    D_80062F5C = start;
    D_80062F2C = (end - start) / var_a1;
    func_8002A748();
}

void func_8002BBB4(void *arg0) {
    D_80062FCC = 0;
    D_80062FD4 = M2C_SFIELD(arg0, u16 *, 4) << 0x10;
    func_8002E428();
}

void func_8002BBEC(void *arg0) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = M2C_SFIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    D_80062FCC = (s16) var_a1;
    D_80062FB4 = (s32) ((M2C_SFIELD(arg0, u16 *, 8) << 0x10) - D_80062FD4) / var_a1;
}

void func_8002BC58(void *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s32 end;
    s32 start;

    temp_v0 = M2C_SFIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    end = M2C_SFIELD(arg0, u16 *, 0xC) << 0x10;
    start = M2C_SFIELD(arg0, u16 *, 8) << 0x10;
    D_80062FCC = (s16) var_a1;
    D_80062FD4 = start;
    D_80062FB4 = (end - start) / var_a1;
}

void func_8002BCCC(u16 *cmd, AkaoChannel *ch) {
    u16 v;

    v = (cmd[2] & 0x7F) << 8;
    ch[1].unk5E = 0;
    ch->unk5E = 0;
    ch[1].unkC6 = v;
    ch->unkC6 = v;
    ch->unkE0 |= 3;
    ch[1].unkE0 |= 3;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002BD04);

void func_8002BDCC(u16 *cmd) {
    func_8002BCCC(cmd, &D_80096608[54]);
    func_8002BCCC(cmd, &D_80096608[52]);
    func_8002BCCC(cmd, &D_80096608[50]);
    func_8002BCCC(cmd, &D_80096608[48]);
}

void func_8002BE2C(void *arg0) {
    func_8002BD04(arg0, &D_80096608[54]);
    func_8002BD04(arg0, &D_80096608[52]);
    func_8002BD04(arg0, &D_80096608[50]);
    func_8002BD04(arg0, &D_80096608[48]);
}

void func_8002BE8C(void *arg0) {
    func_8002BCCC(arg0, &D_80099BA8);
}

void func_8002BEB4(void *cmd) {
    func_8002BD04(cmd, &D_80096608[52]);
}

void func_8002BEDC(void *arg0) {
    func_8002BCCC(arg0, &D_80099998);
}

void func_8002BF04(void *arg0) {
    func_8002BD04(arg0, &D_80099998);
}

void func_8002BF2C(void *cmd) {
    func_8002BCCC(cmd, &D_80096608[48]);
}

void func_8002BF54(void *arg0) {
    func_8002BD04(arg0, &D_80099788);
}

void func_8002BF7C(void *arg0) {
    func_8002BCCC(arg0, &D_80099DB8);
}

void func_8002BFA4(void *cmd) {
    func_8002BD04(cmd, &D_80096608[54]);
}

void func_8002BFCC(void *cmd, AkaoChannel *ch) {
    u16 v;

    v = (*(u16 *)((u8 *)cmd + 4) & 0x7F) << 8;
    ch[1].unk62 = 0;
    ch[0].unk62 = 0;
    ch[1].unk60 = v;
    ch[0].unk60 = v;
    ch[0].unkE0 |= 3;
    ch[1].unkE0 |= 3;
}

void func_8002C004(void *cmd, AkaoChannel *ch) {
    u16 n;

    n = 1;
    if (M2C_SFIELD(cmd, s32 *, 4) != 0) {
        n = M2C_SFIELD(cmd, u16 *, 4);
    }
    M2C_SFIELD(ch, s16 *, 0xCA) = (s16) (((M2C_SFIELD(cmd, u16 *, 8) & 0x7F) << 8) - ch->unk60) / (s16) n;
    M2C_SFIELD(ch + 1, s16 *, 0xCA) = (s16) (((M2C_SFIELD(cmd, u16 *, 8) & 0x7F) << 8) - ch[1].unk60) / (s16) n;
    ch[1].unk62 = n;
    ch->unk62 = n;
}

void func_8002C0CC(void *cmd) {
    func_8002BFCC(cmd, &D_80096608[54]);
    func_8002BFCC(cmd, &D_80096608[52]);
    func_8002BFCC(cmd, &D_80096608[50]);
    func_8002BFCC(cmd, &D_80096608[48]);
}

void func_8002C12C(void *cmd) {
    func_8002C004(cmd, &D_80096608[54]);
    func_8002C004(cmd, &D_80096608[52]);
    func_8002C004(cmd, &D_80096608[50]);
    func_8002C004(cmd, &D_80096608[48]);
}

void func_8002C18C(void *arg0) {
    func_8002BFCC(arg0, &D_80099BA8);
}

void func_8002C1B4(void *arg0) {
    func_8002C004(arg0, &D_80099BA8);
}

void func_8002C1DC(void *cmd) {
    func_8002BFCC(cmd, &D_80096608[50]);
}

void func_8002C204(void *arg0) {
    func_8002C004(arg0, &D_80099998);
}

void func_8002C22C(void *arg0) {
    func_8002BFCC(arg0, &D_80099788);
}

void func_8002C254(void *cmd) {
    func_8002C004(cmd, &D_80096608[48]);
}

void func_8002C27C(void *arg0) {
    func_8002BFCC(arg0, &D_80099DB8);
}

void func_8002C2A4(void *arg0) {
    func_8002C004(arg0, &D_80099DB8);
}

void func_8002C2CC(void *cmd, AkaoChannel *ch) {
    s32 v;

    v = *((s8 *)cmd + 4) << 8;
    M2C_SFIELD(ch + 1, u16 *, 0x5A) = 0;
    M2C_SFIELD(ch, u16 *, 0x5A) = 0;
    M2C_SFIELD(ch + 1, s32 *, 0x3C) = v;
    M2C_SFIELD(ch, s32 *, 0x3C) = v;
    ch->unkE0 |= 0x10;
    ch[1].unkE0 |= 0x10;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002C300);

void func_8002C3A8(void *cmd) {
    func_8002C2CC(cmd, &D_80096608[54]);
    func_8002C2CC(cmd, &D_80096608[52]);
    func_8002C2CC(cmd, &D_80096608[50]);
    func_8002C2CC(cmd, &D_80096608[48]);
}

void func_8002C408(void *arg0) {
    func_8002C300(arg0, &D_80096608[54]);
    func_8002C300(arg0, &D_80096608[52]);
    func_8002C300(arg0, &D_80096608[50]);
    func_8002C300(arg0, &D_80096608[48]);
}

void func_8002C468(void *cmd) {
    func_8002C2CC(cmd, &D_80096608[52]);
}

void func_8002C490(void *arg0) {
    func_8002C300(arg0, &D_80099BA8);
}

void func_8002C4B8(void *arg0) {
    func_8002C2CC(arg0, &D_80099998);
}

void func_8002C4E0(void *cmd) {
    func_8002C300(cmd, &D_80096608[50]);
}

void func_8002C508(void *arg0) {
    func_8002C2CC(arg0, &D_80099788);
}

void func_8002C530(void *arg0) {
    func_8002C300(arg0, &D_80099788);
}

void func_8002C558(void *cmd) {
    func_8002C2CC(cmd, &D_80096608[54]);
}

void func_8002C580(void *arg0) {
    func_8002C300(arg0, &D_80099DB8);
}

void func_8002C5A8(void *arg0) {
    D_80062FE8 = M2C_FIELD(arg0, s8 *, 4) << 0x10;
    D_80062F48 = 0;
}

void func_8002C5C8(void *arg0) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    D_80062F30 = (s32) ((M2C_FIELD(arg0, s8 *, 8) << 0x10) - D_80062FE8) / var_a1;
    D_80062F48 = (s16) var_a1;
}

void func_8002C634(void *arg0) {
    s32 temp_a2;
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    temp_a2 = M2C_FIELD(arg0, s8 *, 4) << 0x10;
    D_80062FE8 = temp_a2;
    var_a1 = 1;
    if (temp_v1 != 0) {
        var_a1 = temp_v1;
    }
    D_80062F30 = (s32) ((M2C_FIELD(arg0, s8 *, 0xC) << 0x10) - temp_a2) / var_a1;
    D_80062F48 = (s16) var_a1;
}

void func_8002C6A8(void *arg0) {
    D_80062FE4 = M2C_FIELD(arg0, s8 *, 4) << 0x10;
    D_80062F40 = 0;
}

void func_8002C6C8(void *arg0) {
    s32 temp_v0;
    s32 var_a1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    var_a1 = 1;
    if (temp_v0 != 0) {
        var_a1 = temp_v0;
    }
    D_80062F28 = (s32) ((M2C_FIELD(arg0, s8 *, 8) << 0x10) - D_80062FE4) / var_a1;
    D_80062F40 = (s16) var_a1;
}

void func_8002C734(void *arg0) {
    s32 temp_a2;
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 8);
    temp_a2 = M2C_FIELD(arg0, s8 *, 4) << 0x10;
    D_80062FE4 = temp_a2;
    var_a1 = 1;
    if (temp_v1 != 0) {
        var_a1 = temp_v1;
    }
    D_80062F28 = (s32) ((M2C_FIELD(arg0, s8 *, 0xC) << 0x10) - temp_a2) / var_a1;
    D_80062F40 = (s16) var_a1;
}

void func_8002C7A8(void) {
    func_80029F44();
}

void func_8002C7C8(void) {
    func_8002A43C();
}

void func_8002C7E8(void) {
    D_8009A104[0].unk0 = 1;
    func_8002A748();
    func_8002A798();
}

void func_8002C81C(void) {
    D_8009A104[0].unk0 = 4;
    func_8002A748();
    func_8002A798();
}

void func_8002C850(void) {
    D_8009A104[0].unk0 = 2;
    func_8002A748();
    func_8002A798();
}

void func_8002C884(s32 *cmd) {
    u16 i;
    AkaoChannel *ch;

    i = 0;
    ch = D_80096608;
    D_80062FD8 = cmd[1];
    do {
        i++;
        ch->unkE0 |= 3;
        ch++;
    } while (i < 24);
}

void func_8002C8C4(void *arg0) {
    D_8009A152 = (s16) M2C_FIELD(arg0, u16 *, 4);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002C8DC);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002C9E4);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002CA84);

void func_8002CB78(void) {
    AkaoChannel *ch;
    u32 bit;
    u32 mask;
    u32 v;

    mask = D_80099FDC;
    if (mask != 0) {
        bit = 0x10000;
        ch = &D_80096608[48];
        do {
            if (mask & bit) {
                mask ^= bit;
                ch->unkE0 |= 0x2203;
            }
            bit <<= 1;
            ch++;
        } while (mask != 0);
        v = D_80099FDC;
        D_80099FDC = 0;
        D_80099FCC = v;
        func_8002FF4C();
        func_80030038();
        func_80030148();
    }
    D_80062FF8 &= ~2;
}

void func_8002CC18(void *arg0) {
    D_80062F70 = M2C_FIELD(arg0, u16 *, 4) & 0x7F;
    D_8009A13C |= 0x80;
}

void func_8002CC44(u8 *cmd) {
    u8 v;

    v = cmd[4];
    D_80062FB8 = v;
    if (v != 0) {
        D_80062FF8 |= 0x10;
    } else {
        D_80062FF8 &= ~0x10;
    }
    func_80030038();
    D_8009A13C |= 0x80;
}

void func_8002CCBC(void) {
    D_80083334[0].id = 0;
}

void func_8002CCCC(void) {
    D_80083334[1].id = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002CCDC);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002CDD0);

void func_8002CEC0(void) {
    s32 mask;
    u32 *playing;

    func_8002CFC0();
    playing = &D_80099FCC;
    mask = ~D_80062F00;
    *playing &= mask;
    D_80099FF0 &= mask;
    func_80030038();
}

void func_8002CF1C(void) {
    u32 *playing;

    func_8002CFC0();
    playing = &D_80099FCC;
    *playing &= ~D_80062F00;
    D_80099FF0 |= D_80062F00;
    func_80030038();
}

void func_8002CF78(void) {
    func_80029A50();
}

void func_8002CF98(void) {
}

void func_8002CFA0(void) {
    func_80038FEC(0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002CFC0);

void func_8002D1E4(void) {
    D_8007EBE8 = 0x1FF93;
    D_8007EC02 = 0;
    D_8007EBEC = 0x77000;
    D_8007EBF0 = 0x77000;
    D_8007EC04 = 0xF;
    D_8007EC06 = 0xF;
    D_8007EC08 = 0x7F;
    D_8007EC0A = 6;
    D_8007EBF4 = 1;
    D_8007EBF8 = 3;
    D_8007EBFC = 3;
    D_8007EC0C = (s16) ((s32) ((D_80062FB0 ^ 0x7F) * D_80062FAC) >> 7);
    D_8007EC00 = D_80062F1E;
    D_8007EC0E = (s16) ((s32) (D_80062FAC * D_80062FB0) >> 7);
    func_8002E23C(0x10, &D_8007EBE4);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002D2D4);

void func_8002D410(void) {
    func_80038FEC(0);
    if (D_80063004 != 0) {
        func_80038A84(0);
        func_80038BC4(0x78000);
        func_80038C04((s32) &func_8002D530);
        func_80038A84(1);
    }
    func_80038C6C(1, D_80062F00);
    D_80099FD8 &= ~D_80062F00;
}

void func_8002D4A0(void) {
    func_80038FEC(0);
    if (D_80063004 != 0) {
        func_80038A84(0);
        func_80038BC4(0x78000);
        func_80038C04((s32) &func_8002D7A0);
        func_80038A84(1);
    }
    func_80038C6C(1, D_80062F00);
    D_80099FD8 &= ~D_80062F00;
}

void func_8002D530(void) {
    if (D_80063004 != 0) {
        func_80038F64(0x77000);
        func_80038F04(D_80062FE0, 0x1000);
        func_80038A84(0);
        if ((u32) D_80063004 >= 0x1001U) {
            func_80038BC4(0x77000);
            func_80038C04((s32) &func_8002D668);
            func_80038A84(1);
            D_80063004 -= 0x1000;
            D_80062FE0 += 0x1000;
            return;
        }
        if (D_80063000 != 0) {
            func_80038BC4(0x77000);
            func_80038C04((s32) &func_8002D668);
            func_80038A84(1);
            D_80062FE0 = D_80063000;
            D_80063004 = D_80062F08;
            return;
        }
        D_80063004 = 0;
        func_80038BC4(0x77000);
        func_80038C04((s32) func_80029A50);
        func_80038A84(1);
    }
}

void func_8002D668(void) {
    if (D_80063004 != 0) {
        func_80038F64(0x78000);
        func_80038F04(D_80062FE0, 0x1000);
        func_80038A84(0);
        if ((u32) D_80063004 >= 0x1001U) {
            func_80038BC4(0x78000);
            func_80038C04((s32) &func_8002D530);
            func_80038A84(1);
            D_80063004 -= 0x1000;
            D_80062FE0 += 0x1000;
            return;
        }
        if (D_80063000 != 0) {
            func_80038BC4(0x78000);
            func_80038C04((s32) &func_8002D530);
            func_80038A84(1);
            D_80062FE0 = D_80063000;
            D_80063004 = D_80062F08;
            return;
        }
        D_80063004 = 0;
        func_80038BC4(0x78000);
        func_80038C04((s32) func_80029A50);
        func_80038A84(1);
    }
}

void func_8002D7A0(void) {
    if (D_80063004 != 0) {
        func_80038F64(0x77000);
        func_80038F04(D_80062FE0, 0x1000);
        func_80038A84(0);
        func_800396C0(0x10, 0x77000);
        func_800396C0(0x11, 0x77800);
        if ((u32) D_80063004 >= 0x1001U) {
            func_80038BC4(0x77000);
            func_80038C04((s32) &func_8002D8E8);
            D_80063004 -= 0x1000;
            D_80062FE0 += 0x1000;
        } else if (D_80063000 != 0) {
            func_80038BC4(0x77000);
            func_80038C04((s32) &func_8002D8E8);
            D_80062FE0 = D_80063000;
            D_80063004 = D_80062F08;
        } else {
            D_80063004 = 0;
            func_80038BC4(0x77000);
            func_80038C04((s32) func_80029A50);
        }
        func_80038A84(1);
    }
}

void func_8002D8E8(void) {
    if (D_80063004 != 0) {
        func_80038F64(0x78000);
        func_80038F04(D_80062FE0, 0x1000);
        func_80038A84(0);
        func_800396C0(0x10, 0x78000);
        func_800396C0(0x11, 0x78800);
        if ((u32) D_80063004 >= 0x1001U) {
            func_80038BC4(0x78000);
            func_80038C04((s32) &func_8002D7A0);
            D_80063004 -= 0x1000;
            D_80062FE0 += 0x1000;
        } else if (D_80063000 != 0) {
            func_80038BC4(0x78000);
            func_80038C04((s32) &func_8002D7A0);
            D_80062FE0 = D_80063000;
            D_80063004 = D_80062F08;
        } else {
            D_80063004 = 0;
            func_80038BC4(0x78000);
            func_80038C04((s32) func_80029A50);
        }
        func_80038A84(1);
    }
}

void func_8002DA30(Slot24 **arg0) {
    *arg0 = D_80081DC8;
    *arg0 = &D_80081DC8[D_80063010];
    D_80063010++;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002DA7C);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002DF88);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002E1A8);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002E23C);

void func_8002E428(void) {
    D_8009C578[0] = 0x1C0;
    D_8009C58C = 0;
    D_8009C58A = D_80062FD6;
    D_8009C588 = D_80062FD6;
    func_80039034(D_8009C578);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002E478);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002E954);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002ED34);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002F24C);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002F738);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002F848);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002FDA0);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002FE48);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8002FF4C);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80030038);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80030148);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80030234);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80030380);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800308D4);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80030E7C);

void func_80031820(AkaoChannel *ch, u16 arg1) {
    u8 *e;
    s32 v;

    M2C_SFIELD(ch, u16 *, 0x58) = arg1;
    e = D_80075F28[arg1];
    M2C_SFIELD(ch, s32 *, 0xE4) = *(s32 *)e;
    M2C_SFIELD(ch, s32 *, 0xE8) = *(s32 *)(e + 4);
    M2C_SFIELD(ch, s32 *, 0xEC) = e[0xD];
    M2C_SFIELD(ch, s32 *, 0xF0) = e[0xE];
    M2C_SFIELD(ch, s32 *, 0xF4) = e[0xF];
    M2C_SFIELD(ch, u16 *, 0xFA) = e[8];
    M2C_SFIELD(ch, u16 *, 0xFC) = e[9];
    M2C_SFIELD(ch, u16 *, 0xFE) = e[0xA];
    M2C_SFIELD(ch, u16 *, 0x100) = e[0xB];
    v = e[0xC];
    ch->unkE0 |= 0x1FF80;
    M2C_SFIELD(ch, u16 *, 0x102) = v;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800318BC);

s32 func_80031A70(u8 **arg0) {
    s32 ret;
    u8 *p;
    u8 len;
    u8 op;

    p = *arg0;
    while (1) {
        op = *p;
        len = D_800499A8[op];
        p += len;
        if (len == 0) {
            ret = 0xA0;
            if (op == 0xCA) {
                ret = 0xCA;
            }
            return ret;
        }
    }
}

void func_80031AB0(u8 **arg0, void *arg1) {
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_v1 = *arg0;
    *arg0 = temp_v1 + 1;
    M2C_FIELD(arg1, s32 *, 0x18) = (s32) (*temp_v1 << 0x10);
    temp_v1_2 = *arg0;
    *arg0 = temp_v1_2 + 1;
    M2C_FIELD(arg1, s32 *, 0x18) = (s32) ((*temp_v1_2 << 0x18) | M2C_FIELD(arg1, s32 *, 0x18));
    M2C_FIELD(arg1, s16 *, 0x48) = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80031AFC);

void func_80031BA0(AkaoChannel *arg0, AkaoChannel *ch) {
    s32 v;

    v = *arg0->addr++ << 16;
    v |= *arg0->addr++ << 24;
    M2C_SFIELD(ch, u16 *, 0x50) = 0;
    ch->unk38 |= 0x80;
    M2C_SFIELD(ch, s32 *, 0x40) = v;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80031BE4);

void func_80031C88(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s32 *, 0x2C) = (s32) *temp_v1;
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 3);
}

void func_80031CB0(AkaoChannel *ch) {
    ch->unk44 = *(s8 *)ch->addr++ << 23;
    ch->unk5C = 0;
    ch->unkE0 |= 3;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80031CE0);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80031D6C);

void func_80031E98(void *arg0, void *arg1) {
    s32 temp_a2;
    u16 var_v1;

    var_v1 = M2C_FIELD(arg0, u16 *, 0x24);
    if (D_80062F04 != 0) {
        var_v1 -= 0x18;
    }
    temp_a2 = M2C_FIELD(arg0, s32 *, 0x38);
    if (temp_a2 & 0x100) {
        M2C_FIELD(arg0, s32 *, 0x38) = (s32) (temp_a2 & ~0x100);
        M2C_FIELD(arg1, s32 *, 0x24) = (s32) (~(1 << var_v1) & M2C_FIELD(arg1, s32 *, 0x24));
    }
}

void func_80031EEC(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xC6) = (s16) (*temp_v1 << 8);
    M2C_FIELD(arg0, s16 *, 0x5E) = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) & 0x100) {
        M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 3);
    }
}

void func_80031F30(void *arg0) {
    s16 temp_a1;
    u8 *temp_v0;
    u8 *temp_v1;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v0 + 1);
    temp_v0_2 = *temp_v0;
    M2C_FIELD(arg0, u16 *, 0x5E) = (u16) temp_v0_2;
    if (temp_v0_2 == 0) {
        M2C_FIELD(arg0, u16 *, 0x5E) = 0x100U;
    }
    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    temp_a1 = M2C_FIELD(arg0, u16 *, 0xC6) & 0xFF00;
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xC8) = (s16) ((s32) ((*temp_v1 << 8) - temp_a1) / (s32) M2C_FIELD(arg0, u16 *, 0x5E));
    M2C_FIELD(arg0, u16 *, 0xC6) = (u16) temp_a1;
}

void func_80031FC0(AkaoChannel *ch) {
    ch->unk60 = *ch->addr++ << 8;
    ch->unk62 = 0;
    ch->unkE0 |= 3;
}

void func_80031FF0(void *arg0) {
    u16 temp_a0;
    u8 *temp_v0;
    u8 *temp_v1;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v0 + 1);
    temp_v0_2 = *temp_v0;
    M2C_FIELD(arg0, u16 *, 0x62) = (u16) temp_v0_2;
    if (temp_v0_2 == 0) {
        M2C_FIELD(arg0, u16 *, 0x62) = 0x100U;
    }
    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    temp_a0 = M2C_FIELD(arg0, u16 *, 0x60) & 0xFF00;
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xCA) = (s16) ((s32) ((*temp_v1 << 8) - temp_a0) / (s32) M2C_FIELD(arg0, u16 *, 0x62));
    M2C_FIELD(arg0, u16 *, 0x60) = temp_a0;
}

void func_80032078(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0x66) = (s16) *temp_v1;
}

void func_80032094(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x66) = (u16) ((M2C_FIELD(arg0, u16 *, 0x66) + 1) & 0xF);
}

void func_800320AC(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0x66) = (u16) ((M2C_FIELD(arg0, u16 *, 0x66) + 0xFFFF) & 0xF);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800320C4);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032274);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800323CC);

void func_800324D8(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xCC) = (s16) (s8) *temp_v1;
}

void func_80032500(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, u16 *, 0xCC) = (u16) ((s8) *temp_v1 + M2C_FIELD(arg0, u16 *, 0xCC));
}

void func_8003252C(void *arg0) {
    u8 *temp_v0;
    u8 *temp_v1;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v0 + 1);
    temp_v0_2 = *temp_v0;
    M2C_FIELD(arg0, s16 *, 0x68) = (s16) temp_v0_2;
    if (temp_v0_2 == 0) {
        M2C_FIELD(arg0, s16 *, 0x68) = 0x100;
    }
    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xD2) = (s16) (s8) *temp_v1;
}

void func_8003257C(void *arg0) {
    u8 *temp_v0;
    u8 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v0 + 1);
    temp_v0_2 = *temp_v0;
    M2C_FIELD(arg0, s16 *, 0x6C) = (s16) temp_v0_2;
    if (temp_v0_2 == 0) {
        M2C_FIELD(arg0, s16 *, 0x6C) = 0x100;
    }
    M2C_FIELD(arg0, s16 *, 0xD4) = 0;
    M2C_FIELD(arg0, s16 *, 0x6A) = 0;
    M2C_FIELD(arg0, s16 *, 0x6E) = 1;
}

void func_800325B8(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6C) = 0;
}

void func_800325C0(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0xCE) = (s16) (s8) *temp_v1;
}

void func_800325E8(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, u16 *, 0xCE) = (u16) ((s8) *temp_v1 + M2C_FIELD(arg0, u16 *, 0xCE));
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032614);

void func_80032718(AkaoChannel *ch) {
    s32 a;
    u32 v;
    s32 lo;
    s32 x;

    x = *ch->addr++ << 8;
    a = M2C_SFIELD(ch, s32 *, 0x30);
    M2C_SFIELD(ch, s16 *, 0x7E) = x;
    v = (u32)(x & 0x7F00) >> 8;
    if (x & 0x8000) {
        lo = v * a;
    } else {
        lo = v * ((a * 15) >> 8);
    }
    M2C_SFIELD(ch, s16 *, 0x7C) = lo >> 7;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032770);

void func_800327E0(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xD6) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~1);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 0x10);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032804);

void func_800328D4(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0x90) = (s16) (*temp_v1 << 8);
}

void func_800328F8(AkaoChannel *ch) {
    u16 n;
    u8 *p;

    p = ch->addr;
    ch->addr = p + 1;
    n = *p;
    if (n == 0) {
        n = 0x100;
    }
    ch->addr = p + 2;
    M2C_SFIELD(ch, s16 *, 0x94) = ((p[1] << 8) - ch->unk90) / n;
    ch->unk92 = n;
}

void func_80032968(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xD8) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~2);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 3);
}

void func_8003298C(AkaoChannel *ch) {
    ch->unk38 |= 4;
    M2C_SFIELD(ch, s16 *, 0x98) = *ch->addr++;
    if (M2C_SFIELD(ch, s16 *, 0x98) == 0) {
        M2C_SFIELD(ch, s16 *, 0x98) = 0x100;
    }
    M2C_SFIELD(ch, u16 *, 0x9C) = *ch->addr++;
    M2C_SFIELD(ch, s32 *, 0x20) = D_8004A5CC[M2C_SFIELD(ch, u16 *, 0x9C)];
    M2C_SFIELD(ch, s16 *, 0x9A) = 1;
}

void func_80032A04(void *arg0) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    M2C_FIELD(arg0, s16 *, 0x9E) = (s16) (*temp_v1 << 7);
}

void func_80032A28(AkaoChannel *ch) {
    s32 n;
    u8 *p;

    p = ch->addr++;
    n = *p;
    if (n == 0) {
        n = 0x100;
    }
    ch->addr++;
    M2C_SFIELD(ch, s16 *, 0xA2) = ((p[1] << 7) - ch->unk9E) / n;
    ch->unkA0 = n;
}

void func_80032A98(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0xDA) = 0;
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~4);
    M2C_FIELD(arg0, s32 *, 0xE0) = (s32) (M2C_FIELD(arg0, s32 *, 0xE0) | 3);
}

void func_80032ABC(void *arg0, void *arg1, s32 arg2) {
    if (M2C_FIELD(arg0, u16 *, 0x54) == 0) {
        M2C_FIELD(arg1, s32 *, 0x2C) = (s32) (arg2 | M2C_FIELD(arg1, s32 *, 0x2C));
    } else {
        D_80099FEC |= arg2;
    }
    D_8009A13C |= 0x10;
    func_8002FF4C();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032B30);

void func_80032BB4(void *arg0, void *arg1, s32 arg2) {
    if (M2C_FIELD(arg0, u16 *, 0x54) == 0) {
        M2C_FIELD(arg1, s32 *, 0x34) = (s32) (arg2 | M2C_FIELD(arg1, s32 *, 0x34));
    } else if (!(arg2 & 0x555555)) {
        D_80099FF4 |= arg2;
    }
    func_80030148();
}

void func_80032C20(AkaoChannel *ch, AkaoSong *song, s32 mask) {
    if (ch->unk54 == 0) {
        song->unk34 &= ~mask;
    } else {
        D_80099FF4 &= ~mask;
    }
    func_80030148();
    ch->unkA6 = 0;
}

void func_80032C8C(void *arg0, void *arg1, s32 arg2) {
    if (M2C_FIELD(arg0, u16 *, 0x54) == 0) {
        M2C_FIELD(arg1, s32 *, 0x30) = (s32) (arg2 | M2C_FIELD(arg1, s32 *, 0x30));
    } else {
        D_80099FF0 |= arg2;
    }
    func_80030038();
}

void func_80032CE8(AkaoChannel *ch, AkaoSong *song, s32 mask) {
    if (ch->unk54 == 0) {
        song->unk30 &= ~mask;
    } else {
        D_80099FF0 &= ~mask;
    }
    func_80030038();
}

void func_80032D44(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6E) = 1;
}

void func_80032D50(void) {
}

void func_80032D58(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x6E) = 4;
}

void func_80032D64(void) {
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032D6C);

void func_80032E08(AkaoChannel *ch) {
    M2C_FIELD(ch, u16 *, 0xFA) = *ch->addr++;
    ch->unkE0 |= 0x900;
    if (ch->unk38 & 0x100) {
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], u16 *, 0xFA) = M2C_FIELD(ch, volatile u16 *, 0xFA);
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80032E6C);

void func_80032ED0(AkaoChannel *ch, AkaoSong *song, s32 mask) {
    u16 v;
    s32 t;

    v = *ch->addr++;
    ch->unkE0 |= 0x8000;
    M2C_SFIELD(ch, u16 *, 0xFE) = v;
    if (ch->unk38 & 0x100) {
        t = M2C_SFIELD(ch, u16 *, 0xFE);
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], u16 *, 0xFE) = t;
    }
}

void func_80032F34(AkaoChannel *ch) {
    M2C_SFIELD(ch, u16 *, 0x100) = *ch->addr++;
    ch->unkE0 |= 0x2200;
    if (ch->unk38 & 0x100) {
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], u16 *, 0x100) = M2C_SFIELD(ch, u16 *, 0x100);
    }
}

void func_80032F98(AkaoChannel *ch) {
    M2C_FIELD(ch, u16 *, 0x102) = *ch->addr++;
    ch->unkE0 |= 0x4400;
    if (ch->unk38 & 0x100) {
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], u16 *, 0x102) = M2C_FIELD(ch, volatile u16 *, 0x102);
    }
}

void func_80032FFC(AkaoChannel *ch) {
    s32 v;
    s32 t;

    v = *ch->addr++;
    ch->unkE0 |= 0x100;
    M2C_SFIELD(ch, s32 *, 0xEC) = v;
    if (ch->unk38 & 0x100) {
        t = *(volatile s32 *)((u8 *)ch + 0xEC);
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], s32 *, 0xEC) = t;
    }
}

void func_80033060(AkaoChannel *ch) {
    s32 v;
    s32 t;

    v = *ch->addr++;
    ch->unkE0 |= 0x200;
    M2C_SFIELD(ch, s32 *, 0xF0) = v;
    if (ch->unk38 & 0x100) {
        t = *(volatile s32 *)((u8 *)ch + 0xF0);
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], s32 *, 0xF0) = t;
    }
}

void func_800330C4(AkaoChannel *ch) {
    M2C_SFIELD(ch, s32 *, 0xF4) = *ch->addr++;
    ch->unkE0 |= 0x400;
    if (ch->unk38 & 0x100) {
        M2C_SFIELD(&D_80096608[M2C_SFIELD(ch, s32 *, 0x24)], s32 *, 0xF4) = M2C_SFIELD(ch, s32 *, 0xF4);
    }
}

void func_80033128(AkaoChannel *ch, AkaoSong *song) {
    u16 i;
    u32 bit;
    u32 used;

    M2C_SFIELD(ch, u16 *, 0x102) = *ch->addr++;
    if (!(ch->unk38 & 0x200)) {
        i = 0;
        bit = 1;
        used = song->active | song->unk24 | song->unk28;
        for (; bit & 0xFFFFFF; bit <<= 1, i++) {
            if (!(used & bit)) {
                break;
            }
        }
        if (bit & 0xFFFFFF) {
            song->unk28 |= bit;
            M2C_SFIELD(ch, s32 *, 0x28) = i;
            ch->unk38 |= 0x200;
        }
    }
}

void func_800331CC(AkaoChannel *ch, AkaoSong *song) {
    u16 v;

    song->unk28 &= ~(1 << M2C_SFIELD(ch, s32 *, 0x28));
    ch->unk38 &= ~0x200;
    v = D_80075F34[M2C_SFIELD(ch, u16 *, 0x58) << 6];
    ch->unkE0 |= 0x4400;
    M2C_SFIELD(ch, u16 *, 0x102) = v;
}

void func_80033224(void *arg0) {
    M2C_FIELD(arg0, u16 *, 0xB8) = (u16) ((M2C_FIELD(arg0, u16 *, 0xB8) + 1) & 3);
    M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0xB8) * 4) + arg0), s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 0);
    M2C_FIELD(((M2C_FIELD(arg0, u16 *, 0xB8) * 2) + arg0), s16 *, 0xBA) = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80033264);

void func_800332EC(AkaoChannel *ch) {
    u16 n;
    u8 lo;
    u8 hi;

    n = *ch->addr++;
    if (n == 0) {
        n = 0x100;
    }
    if (((u16 *)((u8 *)ch + 0xBA))[ch->unkB8] + 1 != n) {
        ch->addr += 2;
    } else {
        lo = *ch->addr++;
        hi = *ch->addr++;
        ch->addr += (s16)(lo | (hi << 8));
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_8003337C);

void func_80033420(AkaoChannel *ch) {
    ((u16 *)((u8 *)ch + 0xBA))[ch->unkB8]++;
    ch->addr = ((u8 **)ch)[ch->unkB8 + 1];
}

void func_8003345C(void *arg0) {
    u8 *temp_v1;
    u8 temp_v1_2;

    temp_v1 = M2C_FIELD(arg0, u8 **, 0);
    M2C_FIELD(arg0, u8 **, 0) = (u8 *) (temp_v1 + 1);
    temp_v1_2 = *temp_v1;
    M2C_FIELD(arg0, s16 *, 0x56) = (s16) (temp_v1_2 | (temp_v1_2 << 8));
    M2C_FIELD(arg0, s16 *, 0xC4) = 0;
    M2C_FIELD(arg0, s16 *, 0xC2) = (s16) temp_v1_2;
}

void func_80033488(AkaoChannel *ch) {
    s16 v;

    v = (s8)*ch->addr++;
    if (v != 0) {
        v += ch->unkC2;
        if (v <= 0) {
            v = 1;
        } else if (v >= 0x100) {
            v = 0xFF;
        }
    }
    ch->unkC4 = v;
}

void func_800334EC(AkaoChannel *ch) {
    u32 lo;
    u32 hi;

    lo = *ch->addr++;
    hi = *ch->addr++;
    ch->start = ch->addr + (s16)(lo | (hi << 8));
    ch->unk38 |= 8;
}

void func_80033534(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~8);
}

void func_80033548(AkaoChannel *ch, AkaoSong *song) {
    song->unk5A = *ch->addr++;
    song->unk56 = *ch->addr++;
    song->unk5C = 0;
    song->unk58 = 0;
}

void func_80033588(u8 **arg0, void *arg1) {
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_v1 = *arg0;
    *arg0 = temp_v1 + 1;
    M2C_FIELD(arg1, u16 *, 0x5E) = (u16) *temp_v1;
    temp_v1_2 = *arg0;
    *arg0 = temp_v1_2 + 1;
    M2C_FIELD(arg1, u16 *, 0x5E) = (u16) (M2C_FIELD(arg1, u16 *, 0x5E) | (*temp_v1_2 << 8));
}

void func_800335CC(void *arg0, AkaoChannel *ch) {
    ch->unk54 = 1;
}

void func_800335D8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    func_80032E6C();
    func_80032ED0(arg0, arg1, arg2);
}

void func_80033628(AkaoChannel *ch, void *arg1, s32 arg2) {
    u8 n;

    n = *ch->addr++;
    if (n == 0) {
        ch->unkA4 = 0x101;
    } else {
        ch->unkA4 = n + 1;
    }
    func_80032ABC(ch, arg1, arg2);
}

void func_8003366C(AkaoChannel *ch) {
    u8 n;

    n = *ch->addr++;
    if (n == 0) {
        ch->unkA4 = 0x101;
    } else {
        ch->unkA4 = n + 1;
    }
}

void func_80033698(AkaoChannel *ch, void *arg1, s32 arg2) {
    u8 n;

    n = *ch->addr++;
    if (n == 0) {
        ch->unkA6 = 0x101;
    } else {
        ch->unkA6 = n + 1;
    }
    func_80032BB4(ch, arg1, arg2);
}

void func_800336DC(AkaoChannel *ch) {
    s16 n;

    n = *ch->addr++;
    if (n == 0) {
        n = 0x101;
    } else {
        n++;
    }
    ch->unkA6 = n;
}

void func_80033708(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~0x37);
    func_80032B30();
    func_80032C20(arg0, arg1, arg2);
    func_80032CE8(arg0, arg1, arg2);
    M2C_FIELD(arg0, u16 *, 0x6E) = (u16) (M2C_FIELD(arg0, u16 *, 0x6E) & 0xFFFA);
}

void func_80033788(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) | 0x10);
}

void func_8003379C(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~0x10);
}

void func_800337B0(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) | 0x20);
}

void func_800337C4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) & ~0x20);
}

void func_800337D8(AkaoChannel *ch) {
    u8 lo;
    u8 hi;

    lo = *ch->addr++;
    hi = *ch->addr++;
    ch->addr += (s16)(lo | (hi << 8));
}

void func_80033818(u8 **pp, AkaoSong *song) {
    s32 t;
    s32 lo;
    s32 hi;

    t = *(*pp)++;
    if (song->unk4E != 0 && song->unk4E >= t) {
        lo = *(*pp)++;
        hi = *(*pp)++;
        *pp += (s16)(lo | (hi << 8));
        song->unk4C = t;
    } else {
        *pp += 2;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80033894);

void func_80033A70(void) {
    func_80033894();
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80033A90);

void func_80033B70(void) {
    do {

    } while (func_8003DBD0() == 0);
    D_80071A60 = 0;
    func_8003DDA4(0);
    func_80034F3C();
    func_8003E100(0xE, 0x80, 0);
    func_8003CEDC(3);
    D_80071A64 = func_80034350();
    func_80034F5C();
}

void func_80033BE0(void) {
    func_8003408C();
    do {

    } while (func_80034B44() != 0);
    func_8003DD84();
    func_8003DD18(0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80033C20);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80033CB8);

s32 func_80033DAC(s32 arg0, s32 arg1) {
    func_80033CB8(1, arg0, 0, 0, arg1);
    return 0;
}

s32 func_80033DE4(s32 arg0) {
    func_80033CB8(0, arg0, 0, 0, 0);
    do {

    } while (func_8003DE9C(2, &D_80071A68, 0) == 0);
    return 0;
}

s32 func_80033E34(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80033CB8(3, arg0, arg1, arg2, arg3);
    return 0;
}

s32 func_80033E74(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80033CB8(0xB, arg0, arg1, arg2, arg3);
    D_800698E8 = arg0;
    func_80034D2C((s32) &D_800698F0, arg2);
    return 0;
}

s32 func_80033EDC(s32 arg0, s32 arg1) {
    do {

    } while (func_80033DAC(arg0, arg1) != 0);
loop_2:
    if (func_80034B44() != 0) {
        func_8003CEDC(0);
        goto loop_2;
    }
    return 0;
}

s32 func_80033F40(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    do {

    } while (func_80033E34(arg0, arg1, arg2, arg3) != 0);
loop_2:
    if (func_80034B44() != 0) {
        func_8003CEDC(0);
        goto loop_2;
    }
    return 0;
}

s32 func_80033FC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    do {

    } while (func_80033E74(arg0, arg1, arg2, arg3) != 0);
loop_2:
    if (func_80034B44() != 0) {
        func_8003CEDC(0);
        goto loop_2;
    }
    return 0;
}

void func_80034048(void) {
    D_80071A6C = 0;
    D_80071A80 = 0;
    D_80071A84 = NULL;
    D_80071A60 = 0x13;
    func_80034B44();
}

void func_8003408C(void) {
    switch (D_80071A60) {
    case 5:
    case 6:
    case 13:
    case 14:
        func_8003DE6C(0);
        func_8003DE84(0);
        func_80034048();
        break;
    case 8:
    case 9:
    case 10:
        func_80035658();
        break;
    case 0:
    case 7:
        break;
    case 18:
    default:
        func_80034048();
        break;
    }
}

void func_80034104(void) {
    func_8003E100(0xE, 0, 0);
    func_8003CEDC(3);
    func_8003E100(8, 0, 0);
    D_80071A60 = 7;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034150);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034350);

void func_800343F0(void) {
    func_80034350();
}

s32 func_80034410(void) {
    return D_80071A60;
}

void func_80034420(void) {
}

void func_80034428(void) {
}

void func_80034430(void) {
    D_80071A60 = 0x10;
}

void func_80034444(void) {
    D_80071A60 = 0;
    if (D_80071A84 != NULL) {
        D_80071A84();
    }
}

void func_8003447C(void) {
    func_8003DFD4(2, (s32) &D_80071A68);
    D_80071A60 = 2;
    D_8006E0F4 = 0;
    D_800698EC = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800344C0);

void func_800345BC(void) {
    func_8003DFD4(2, (s32) &D_80071A68);
    D_80071A60 = 4;
    D_8006E0F4 = 0;
    D_800698EC = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034600);

void func_800346F8(void) {
    if (func_80041D28(D_80071A6C, D_80071A80, 0x80) == 0) {
        D_80071A60 = 3;
        func_80034CAC(0x10);
        return;
    }
    D_80071A60 = 6;
}

void func_80034754(void) {
    s32 temp_v0;

    temp_v0 = func_80041E30(1, 0);
    switch (temp_v0) {
    case 0:
        D_80071A60 = 0x11;
        return;
    case -1:
        D_80071A60 = 3;
        func_80034CAC(3);
        return;
    }
}

void func_800347B4(void) {
    func_8003DFD4(2, (s32) &D_80071A68);
    D_80071A60 = 0xC;
    D_8006E0F4 = 0;
    D_800698EC = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800347F8);

void func_800348F4(void) {
    D_8006E0F8 = D_80071A6C;
    if ((u32) D_80071A6C >= 9U) {
        D_8006E0F8 = 9;
    }
    if (func_80041D28(D_8006E0F8, (s32) &D_800698F0, 0x80) == 0) {
        D_80071A60 = 0xB;
        func_80034CAC(3);
        return;
    }
    D_80071A60 = 0xE;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034974);

void func_80034A58(void) {
    func_8003DFD4(9, 0);
    D_80071A60 = 0x14;
    D_8006E0F4 = 0;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034A90);

s32 func_80034B44(void) {
    s32 *p;

    if ((u32) D_80071A60 >= 0x15U) {
        while (1) {
        }
    }
    p = &D_80071A60;
    D_8004A634[*p]();
    return *p;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034BB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034CAC);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034D18);

void func_80034D2C(s32 arg0, s32 arg1) {
    D_80034CF0 = arg0;
    D_80034CF4 = arg1;
    D_80034CFC = arg1;
    jtbl_80034D14 = &func_80034E00;
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034D5C);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034DB0);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034E00);

void func_80034F3C(void) {
    func_80041F14(0);
}

void func_80034F5C(void) {
    u8 file[24];
    s32 r;

    do {
        while (func_8003FB8C((M2C_UNK *)file, "\\MINT\\MOVIE_ID.BIN;1") == 0) {
        }
        func_8003E100(2, (s32)file, 0);
        func_80041D28(1, (s32)&D_8009A1F4, 0x80);
        while ((r = func_80041E30(1, 0)) > 0) {
        }
    } while (r != 0);
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80034FC8);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035430);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_800354CC);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035658);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035744);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035CF0);

void func_80035D64(void) {
    D_80071A60 = 9;
    if (D_80095DC4 == 0) {
loop_1:
        if (func_80040594(0x1E0) == 0) {
            do {

            } while (func_8003DE9C(2, &D_80071A68, 0) == 0);
            goto loop_1;
        }
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035DC8);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80035F14);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80036038);

void func_80036100(void) {
    s32 n;

    if (D_80071A60 == 8) {
        n = 0x800000;
        while (D_8006E118 == 0) {
            if (--n == 0) {
                D_8006E118 = 1;
                D_80095DB4[0] = D_80095DB4[4] + D_80095DB4[-22];
                D_80095DB4[1] = D_80095DB4[5] + D_80095DB4[-20];
            }
        }
        D_8006E118 = 0;
    }
}

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80036190);

INCLUDE_ASM("../asm/us/main/nonmatchings/akao", func_80036244);
