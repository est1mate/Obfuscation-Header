
#if _MSC_VER && _WIN64 == 1
#include <intrin.h>
#include <windows.h>
#include <winternl.h>

unsigned constexpr long long const_hash(const char* input) {
    return *input ? static_cast<unsigned long long>(*input) + 33 * const_hash(input + 1) : 5381;
}

#define RAND_BYTE(n) (unsigned char)((const_hash(__DATE__ __TIME__) + (__COUNTER__ + n) * (__COUNTER__ + n) * 0xDEADBEEF) % 0xFF)

#define ASM_OBFUSCATE_1 do { \
    __asm { \
        __asm push rax \
        __asm xor rax, rax \
        __asm mov rax, gs:[0x60] \
        __asm xor rax, rax \
        __asm pop rax \
    } \
} while(0)

#define ASM_OBFUSCATE_2 do { \
    __asm { \
        __asm push rbx \
        __asm rdtsc \
        __asm xor rbx, rax \
        __asm xor rbx, rdx \
        __asm pop rbx \
    } \
} while(0)

#define ASM_FAKE_CALL do { \
    __asm { \
        __asm jmp skip_fake \
        __asm call fake_target \
        __asm fake_target: \
        __asm ret \
        __asm skip_fake: \
        __asm nop \
    } \
} while(0)

#define STUB_1 0xEB, 0x08, 0x48, 0x89, 0x8C, 0x24, RAND_BYTE(0), RAND_BYTE(1), RAND_BYTE(2), RAND_BYTE(3), 0xC3
#define STUB_2 0xEB, 0x0A, 0x48, 0x89, 0x94, 0x24, RAND_BYTE(4), RAND_BYTE(5), RAND_BYTE(6), RAND_BYTE(7), 0x90, 0x90, 0xC3
#define STUB_3 0xEB, 0x0C, 0x4C, 0x89, 0x84, 0x24, RAND_BYTE(8), RAND_BYTE(9), RAND_BYTE(10), RAND_BYTE(11), 0x48, 0x31, 0xC0, 0x90, 0xC3
#define STUB_4 0xEB, 0x0E, 0x4C, 0x89, 0x8C, 0x24, RAND_BYTE(12), RAND_BYTE(13), RAND_BYTE(14), RAND_BYTE(15), 0x48, 0x83, 0xC0, 0x01, 0x48, 0x31, 0xDB, 0xC3
#define STUB_5 0xEB, 0x10, 0x48, 0x89, 0xAC, 0x24, RAND_BYTE(16), RAND_BYTE(17), RAND_BYTE(18), RAND_BYTE(19), 0x48, 0x31, 0xC9, 0x48, 0x31, 0xD2, 0x90, 0x90, 0xC3
#define STUB_6 0xEB, 0x12, 0x48, 0x89, 0xB4, 0x24, RAND_BYTE(20), RAND_BYTE(21), RAND_BYTE(22), RAND_BYTE(23), 0x48, 0x83, 0xC1, 0x02, 0x48, 0x83, 0xC2, 0x03, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_7 0xEB, 0x14, 0x48, 0x89, 0xBC, 0x24, RAND_BYTE(24), RAND_BYTE(25), RAND_BYTE(26), RAND_BYTE(27), 0x48, 0x31, 0xFF, 0x48, 0x31, 0xF6, 0x48, 0x31, 0xED, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_8 0xEB, 0x16, 0x4C, 0x89, 0xA4, 0x24, RAND_BYTE(28), RAND_BYTE(29), RAND_BYTE(30), RAND_BYTE(31), 0x4D, 0x31, 0xE4, 0x4D, 0x31, 0xED, 0x4D, 0x31, 0xF6, 0x4D, 0x31, 0xFF, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_9 0xEB, 0x18, 0x4C, 0x89, 0xAC, 0x24, RAND_BYTE(32), RAND_BYTE(33), RAND_BYTE(34), RAND_BYTE(35), 0x48, 0x83, 0xC0, 0x05, 0x48, 0x83, 0xC3, 0x06, 0x48, 0x83, 0xC1, 0x07, 0x48, 0x83, 0xC2, 0x08, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_10 0xEB, 0x1A, 0x4C, 0x89, 0xB4, 0x24, RAND_BYTE(36), RAND_BYTE(37), RAND_BYTE(38), RAND_BYTE(39), 0x48, 0x31, 0xC0, 0x48, 0x31, 0xDB, 0x48, 0x31, 0xC9, 0x48, 0x31, 0xD2, 0x48, 0x31, 0xFF, 0x48, 0x31, 0xF6, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_11 0xEB, 0x1C, 0x48, 0x8B, 0x84, 0x24, RAND_BYTE(40), RAND_BYTE(41), RAND_BYTE(42), RAND_BYTE(43), 0x48, 0xC1, 0xC0, 0x07, 0x48, 0xF7, 0xD0, 0x48, 0xC1, 0xC8, 0x0D, 0x48, 0x35, RAND_BYTE(44), RAND_BYTE(45), RAND_BYTE(46), RAND_BYTE(47), 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_12 0xEB, 0x1E, 0x4C, 0x8B, 0x8C, 0x24, RAND_BYTE(48), RAND_BYTE(49), RAND_BYTE(50), RAND_BYTE(51), 0x49, 0xC1, 0xC1, 0x11, 0x49, 0xF7, 0xD1, 0x49, 0x81, 0xF1, RAND_BYTE(52), RAND_BYTE(53), RAND_BYTE(54), RAND_BYTE(55), 0x4D, 0x31, 0xC9, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_13 0xEB, 0x20, 0x48, 0xB8, RAND_BYTE(56), RAND_BYTE(57), RAND_BYTE(58), RAND_BYTE(59), RAND_BYTE(60), RAND_BYTE(61), RAND_BYTE(62), RAND_BYTE(63), 0x48, 0xC1, 0xC0, 0x1F, 0x48, 0x35, RAND_BYTE(64), RAND_BYTE(65), RAND_BYTE(66), RAND_BYTE(67), 0x48, 0xF7, 0xD8, 0x48, 0xC1, 0xC8, 0x09, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_14 0xEB, 0x22, 0x4C, 0xB9, RAND_BYTE(68), RAND_BYTE(69), RAND_BYTE(70), RAND_BYTE(71), RAND_BYTE(72), RAND_BYTE(73), RAND_BYTE(74), RAND_BYTE(75), 0x49, 0xC1, 0xC9, 0x17, 0x49, 0xF7, 0xD9, 0x49, 0x81, 0xC1, RAND_BYTE(76), RAND_BYTE(77), RAND_BYTE(78), RAND_BYTE(79), 0x4D, 0x31, 0xC1, 0x4D, 0x31, 0xC9, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_15 0xEB, 0x24, 0x48, 0x89, 0xC8, 0x48, 0xC1, 0xC0, 0x0B, 0x48, 0x31, 0xC8, 0x48, 0xC1, 0xC8, 0x15, 0x48, 0xF7, 0xD0, 0x48, 0x35, RAND_BYTE(80), RAND_BYTE(81), RAND_BYTE(82), RAND_BYTE(83), 0x48, 0xC1, 0xC0, 0x1D, 0x48, 0x31, 0xC8, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_16 0xEB, 0x26, 0x4C, 0x89, 0xD0, 0x49, 0xC1, 0xCA, 0x13, 0x4C, 0x31, 0xD0, 0x48, 0xC1, 0xC8, 0x19, 0x48, 0xF7, 0xD8, 0x48, 0x81, 0xC0, RAND_BYTE(84), RAND_BYTE(85), RAND_BYTE(86), RAND_BYTE(87), 0x48, 0xC1, 0xC0, 0x0F, 0x4C, 0x31, 0xD0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_17 0xEB, 0x28, 0x48, 0x8B, 0xC3, 0x48, 0xC1, 0xC3, 0x1B, 0x48, 0x31, 0xD8, 0x48, 0xF7, 0xD3, 0x48, 0xC1, 0xCB, 0x0D, 0x48, 0x81, 0xF3, RAND_BYTE(88), RAND_BYTE(89), RAND_BYTE(90), RAND_BYTE(91), 0x48, 0x31, 0xD8, 0x48, 0xC1, 0xC3, 0x11, 0x48, 0x31, 0xD8, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_18 0xEB, 0x2A, 0x4C, 0x8B, 0xC4, 0x49, 0xC1, 0xC4, 0x1D, 0x4C, 0x31, 0xE0, 0x49, 0xF7, 0xD4, 0x49, 0xC1, 0xCC, 0x17, 0x49, 0x81, 0xC4, RAND_BYTE(92), RAND_BYTE(93), RAND_BYTE(94), RAND_BYTE(95), 0x4C, 0x31, 0xE0, 0x49, 0xC1, 0xC4, 0x0B, 0x4C, 0x31, 0xE0, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_19 0xEB, 0x2C, 0x48, 0x8B, 0xC5, 0x48, 0xC1, 0xC5, 0x0F, 0x48, 0x31, 0xE8, 0x48, 0xF7, 0xD5, 0x48, 0xC1, 0xCD, 0x1F, 0x48, 0x35, RAND_BYTE(96), RAND_BYTE(97), RAND_BYTE(98), RAND_BYTE(99), 0x48, 0x31, 0xE8, 0x48, 0xC1, 0xC5, 0x13, 0x48, 0x31, 0xE8, 0x48, 0xF7, 0xD5, 0x90, 0x90, 0x90, 0x90, 0xC3
#define STUB_20 0xEB, 0x2E, 0x4C, 0x8B, 0xC6, 0x49, 0xC1, 0xC6, 0x19, 0x4C, 0x31, 0xF0, 0x49, 0xF7, 0xD6, 0x49, 0xC1, 0xCE, 0x0D, 0x49, 0x81, 0xF6, RAND_BYTE(100), RAND_BYTE(101), RAND_BYTE(102), RAND_BYTE(103), 0x4C, 0x31, 0xF0, 0x49, 0xC1, 0xC6, 0x17, 0x4C, 0x31, 0xF0, 0x49, 0xF7, 0xD6, 0x90, 0x90, 0x90, 0x90, 0xC3

#define JUNK_HEAVY do { \
    volatile unsigned long long _j1 = __rdtsc() ^ RAND_BYTE(0); \
    volatile unsigned long long _j2 = (unsigned long long)__readgsqword(0x60) ^ _j1; \
 \
    if (((_j1 * _j1) & 1) == ((_j1 & 1) ^ (_j1 & 1))) { \
 \
        if (_j1 & 0xFF) { \
            if (_j1 & 0x1) { \
                _j2 = (_j2 << 17) | (_j2 >> 47); \
 \
                if ((_j2 ^ (_j2 >> 32)) & 0xFF00) { \
                    if (_j2 & 0x100) { \
                        _j1 ^= _j2; \
 \
                        for (volatile int _vmp_i = 0; _vmp_i < ((_j1 & 0x1) ? 1 : 0); _vmp_i++) { \
                            if (_j1 > _j2) { \
                                if (_j1 & 0x1000) { \
                                    _j1 = ~_j1; \
                                } else { \
                                    _j1 += __rdtsc(); \
                                } \
                            } else { \
                                if (_j2 & 0x2000) { \
                                    _j2 = ~_j2; \
                                } else { \
                                    _j2 ^= __rdtsc(); \
                                } \
                            } \
                        } \
                    } else { \
                        _j1 += _j2; \
                        if (_j1 & 0x4000) { \
                            _j1 = (_j1 << 7) | (_j1 >> 57); \
                        } \
                    } \
                } else { \
                    _j1 += _j2; \
                    if (_j1 & 0x8000) { \
                        _j1 ^= 0xDEADBEEF; \
                    } \
                } \
            } else { \
                _j2 ^= __rdtsc(); \
 \
                if (((_j2 | ~_j2) == ~0ULL) && (_j2 & 0x10000)) { \
                    if (_j2 & 0x20000) { \
                        _j2 = (_j2 << 13) | (_j2 >> 51); \
                    } else { \
                        _j2 = ~_j2; \
                    } \
                } \
            } \
        } else { \
            if (_j2 & 0x2) { \
                _j2 ^= __rdtsc(); \
                if (_j2 & 0x40000) { \
                    _j2 = (_j2 << 19) | (_j2 >> 45); \
                } \
            } else { \
                _j1 += _j2; \
            } \
        } \
    } \
 \
    if (((_j1 & _j2) ^ (_j1 & _j2)) != 0) { \
        _j1 = 0xDEADC0DE;  \
    } \
    volatile unsigned long long _j3 = (_j1 ^ _j2) + ((_j1 & _j2) << 1); \
 \
    if (((_j3 * 2) >> 1) == _j3) { \
        if ((_j3 & 0xF) == 0x5) { \
            if (_j3 > 0x1000000) { \
                if (_j3 & 0x80000) { \
                    _j3 = ~_j3; \
 \
                    for (volatile int _k = 0; _k < (((_j3 & 0x100000) ? 1 : 0) + ((_j3 & 0x100000) ? 0 : 1)); _k++) { \
                        if (_j3 & 0x100000) { \
                            _j3 ^= 0xDEADBEEF; \
                        } else { \
                            _j3 = (_j3 << 11) | (_j3 >> 53); \
                        } \
                    } \
                } else { \
                    _j3 ^= __rdtsc(); \
                } \
            } else { \
                if (_j3 & 0x200000) { \
                    _j3 = (_j3 << 23) | (_j3 >> 41); \
                } \
            } \
        } else if ((_j3 & 0xF) == 0xA) { \
            if (_j3 < 0x2000000) { \
                _j3 = (_j3 << 13) | (_j3 >> 51); \
                if (_j3 & 0x400000) { \
                    _j3 = ~_j3; \
                } \
            } else { \
                _j3 += __rdtsc(); \
            } \
        } else if ((_j3 & 0xF) == 0x3) { \
            if (_j3 & 0x800000) { \
                if (_j3 & 0x1000000) { \
                    _j3 ^= 0xCAFEBABE; \
                } else { \
                    _j3 = (_j3 << 17) | (_j3 >> 47); \
                } \
            } \
        } else { \
            _j3 += __rdtsc(); \
        } \
    } \
    volatile unsigned long long _j4 = ~(_j3 - _j2) ^ __rdtsc(); \
    if (_j4 == 0) {  \
 \
    volatile int _vmp_state = (_j4 & 0xF); \
    while (_vmp_state >= 0) { \
        switch (_vmp_state) { \
            case 0: \
                if (_j4 & 0x2000000) { \
                    _j4 ^= 0xCAFEBABE; \
                    if (_j4 > _j1) { \
                        _j4 = ~_j4; \
                    } \
                } else { \
                    _j4 += _j1; \
                } \
                _vmp_state = -1; \
                break; \
            case 1: \
                if (_j4 & 0x4000000) { \
                    _j4 = ~_j4; \
                    if (_j4 < _j2) { \
                        _j4 ^= __rdtsc(); \
                    } \
                } \
                _vmp_state = -1; \
                break; \
            case 2: \
                _j4 = (_j4 << 7) | (_j4 >> 57); \
                if (_j4 & 0x8000000) { \
                    if (_j4 & 0x10000000) { \
                        _j4 ^= _j1; \
                    } else { \
                        _j4 += _j2; \
                    } \
                } \
                _vmp_state = -1; \
                break; \
            case 3: \
                _j4 += _j1; \
                if (_j4 > 0x20000000) { \
                    _j4 = (_j4 << 11) | (_j4 >> 53); \
                } \
                _vmp_state = -1; \
                break; \
            case 4: \
                if (_j4 & 0x40000000) { \
                    _j4 ^= _j2; \
                    if (_j4 & 0x80000000ULL) { \
                        _j4 = ~_j4; \
                    } \
                } else { \
                    _j4 = (_j4 << 13) | (_j4 >> 51); \
                } \
                _vmp_state = -1; \
                break; \
            case 5: \
                _j4 = (_j4 << 11) | (_j4 >> 53); \
                if (_j4 < 0x100000000ULL) { \
                    _j4 ^= __rdtsc(); \
                } \
                _vmp_state = -1; \
                break; \
            case 6: \
                if (_j4 > _j3) { \
                    _j4 -= _j3; \
                    if (_j4 & 0x200000000ULL) { \
                        _j4 = ~_j4; \
                    } \
                } else { \
                    _j4 += _j3; \
                } \
                _vmp_state = -1; \
                break; \
            case 7: \
                _j4 ^= __rdtsc(); \
                if (_j4 & 0x400000000ULL) { \
                    if (_j4 & 0x800000000ULL) { \
                        _j4 = (_j4 << 17) | (_j4 >> 47); \
                    } \
                } \
                _vmp_state = -1; \
                break; \
            case 8: \
                if (_j4 & 0x1000000000ULL) { \
                    _j4 = (_j4 << 19) | (_j4 >> 45); \
                } else { \
                    _j4 ^= 0xDEADBEEF; \
                } \
                _vmp_state = -1; \
                break; \
            case 9: \
                _j4 += _j2; \
                if (_j4 > 0x2000000000ULL) { \
                    _j4 = ~_j4; \
                } \
                _vmp_state = -1; \
                break; \
            case 10: \
                if (_j4 < _j1) { \
                    _j4 = ~_j4 ^ _j1; \
                } else { \
                    _j4 = (_j4 << 23) | (_j4 >> 41); \
                } \
                _vmp_state = -1; \
                break; \
            case 11: \
                _j4 = (_j4 << 29) | (_j4 >> 35); \
                if (_j4 & 0x4000000000ULL) { \
                    _j4 ^= _j3; \
                } \
                _vmp_state = -1; \
                break; \
            case 12: \
                if (_j4 & 0x8000000000ULL) { \
                    _j4 ^= 0xFEEDFACE; \
                } else { \
                    _j4 = ~_j4; \
                } \
                _vmp_state = -1; \
                break; \
            case 13: \
                _j4 *= (_j1 | 1); \
                if (_j4 > 0x10000000000ULL) { \
                    _j4 = (_j4 << 5) | (_j4 >> 59); \
                } \
                _vmp_state = -1; \
                break; \
            case 14: \
                if (_j4 & 0x20000000000ULL) { \
                    _j4 = (_j4 << 31) | (_j4 >> 33); \
                } else { \
                    _j4 += __rdtsc(); \
                } \
                _vmp_state = -1; \
                break; \
            default: \
                if (_j4 > _j2) { \
                    _j4 ^= __rdtsc(); \
                } else { \
                    _j4 = ~_j4; \
                } \
                _vmp_state = -1; \
                break; \
        } \
    } \
    volatile unsigned long long _j5 = (_j4 * (_j3 | 1)) ^ (unsigned long long)__readgsqword(0x30); \
 \
    if (((_j5 ^ 0) == _j5) || ((_j5 & 0) == 0)) { \
        if (_j5 < _j4) { \
            if (_j5 & 0x100) { \
                _j5 = ~_j5; \
                if (_j5 & 0x200) { \
                    if (_j5 > _j1) { \
                        _j5 ^= _j1; \
                    } else { \
                        _j5 += _j2; \
                    } \
                } else { \
                    _j5 = (_j5 << 7) | (_j5 >> 57); \
                } \
            } else { \
                if (_j5 & 0x400) { \
                    _j5 ^= __rdtsc(); \
                } else { \
                    _j5 = (_j5 << 13) | (_j5 >> 51); \
                } \
            } \
        } else { \
            if (_j5 & 0x800) { \
                _j5 += _j2; \
                if (_j5 & 0x1000) { \
                    if (_j5 > 0x40000000000ULL) { \
                        _j5 = (_j5 << 19) | (_j5 >> 45); \
                    } else { \
                        _j5 = ~_j5; \
                    } \
                } else { \
                    _j5 ^= 0xCAFEBABE; \
                } \
            } else { \
                if (_j5 & 0x2000) { \
                    _j5 = (_j5 << 23) | (_j5 >> 41); \
                } else { \
                    _j5 += __rdtsc(); \
                } \
            } \
        } \
    } \
 \
    volatile unsigned long long _j6 = (_j5 ^ _j4 ^ _j3) + __rdtsc(); \
    if (((_j6 | ~_j6) == ~0ULL) && (((_j6 & 0xFF) < 0x100) || ((_j6 & 0xFF) >= 0))) { \
        volatile int _extra_state = (_j6 ^ _j1) & 0x1F; \
        volatile int _extra_done = 0; \
        while (!_extra_done) { \
            if (((_extra_state & 0) == 0) && ((_extra_state | 0) == _extra_state)) { \
                switch (_extra_state) { \
                    case 0: \
                        _j6 ^= 0xFEDCBA9876543210ULL; \
                        if (_j6 & 0x1) { _j6 = (_j6 << 7) | (_j6 >> 57); } \
                        _extra_done = 1; break; \
                    case 1: \
                        _j6 = ~_j6; \
                        if (_j6 > _j1) { _j6 += _j2; } else { _j6 ^= _j3; } \
                        _extra_done = 1; break; \
                    case 2: \
                        _j6 = (_j6 << 13) | (_j6 >> 51); \
                        if ((_j6 ^ (_j6 >> 24)) & 0xFF) { _j6 ^= __rdtsc(); } \
                        _extra_done = 1; break; \
                    case 3: \
                        _j6 += _j4; \
                        if (_j6 & 0x10) { _j6 = ~_j6; } \
                        _extra_done = 1; break; \
                    case 4: \
                        _j6 ^= _j5; \
                        if (_j6 < _j2) { _j6 = (_j6 << 17) | (_j6 >> 47); } \
                        _extra_done = 1; break; \
                    case 5: \
                        _j6 = (_j6 << 19) | (_j6 >> 45); \
                        if (_j6 & 0x100) { _j6 += _j1; } \
                        _extra_done = 1; break; \
                    case 6: \
                        _j6 -= _j3; \
                        if (_j6 > 0x1000) { _j6 ^= 0xCAFEBABE; } \
                        _extra_done = 1; break; \
                    case 7: \
                        _j6 ^= __rdtsc(); \
                        if (_j6 & 0x1000) { _j6 = (_j6 << 23) | (_j6 >> 41); } \
                        _extra_done = 1; break; \
                    case 8: \
                        _j6 = (_j6 << 11) | (_j6 >> 53); \
                        if (_j6 & 0x10000) { _j6 = ~_j6; } \
                        _extra_done = 1; break; \
                    case 9: \
                        _j6 += _j2; \
                        if (_j6 > _j5) { _j6 ^= _j4; } \
                        _extra_done = 1; break; \
                    case 10: \
                        _j6 = ~_j6 ^ _j1; \
                        if (_j6 & 0x100000) { _j6 += __rdtsc(); } \
                        _extra_done = 1; break; \
                    case 11: \
                        _j6 = (_j6 << 29) | (_j6 >> 35); \
                        if (_j6 < _j3) { _j6 ^= _j5; } \
                        _extra_done = 1; break; \
                    case 12: \
                        _j6 ^= 0xDEADBEEF; \
                        if (_j6 & 0x1000000) { _j6 = (_j6 << 5) | (_j6 >> 59); } \
                        _extra_done = 1; break; \
                    case 13: \
                        _j6 *= (_j1 | 1); \
                        if (_j6 > 0x10000000) { _j6 = ~_j6; } \
                        _extra_done = 1; break; \
                    case 14: \
                        _j6 = (_j6 << 31) | (_j6 >> 33); \
                        if (_j6 & 0x100000000ULL) { _j6 += _j2; } \
                        _extra_done = 1; break; \
                    case 15: \
                        _j6 ^= (unsigned long long)__readgsqword(0x60); \
                        if (_j6 < 0x1000000000ULL) { _j6 = (_j6 << 15) | (_j6 >> 49); } \
                        _extra_done = 1; break; \
                    default: \
                        _j6 ^= _j1 ^ _j2 ^ _j3; \
                        if (_j6 & 0x10000000000ULL) { _j6 = ~_j6; } \
                        _extra_done = 1; break; \
                } \
            } else { \
                _extra_done = 1; \
            } \
        } \
 \
        for (volatile int _nest1 = 0; _nest1 < (((_j6 & 0x4) == 0x4) ? 1 : ((_j6 & 0x4) == 0) ? 1 : 1); _nest1++) { \
            if (_j6 & 0x100000000000ULL) { \
                _j6 = (_j6 << 21) | (_j6 >> 43); \
                for (volatile int _nest2 = 0; _nest2 < (((_j6 & 0x8) == 0x8) ? 1 : 1); _nest2++) { \
                    if (_j6 > _j1) { \
                        _j6 ^= __rdtsc(); \
                    } else { \
                        _j6 += _j2; \
                    } \
                } \
            } else { \
                _j6 = ~_j6; \
            } \
        } \
    } \
} } while(0)

#define BRKIDA_EXTREME do { \
        JUNK_HEAVY; \
        volatile unsigned long long _m1 = __rdtsc(); \
        volatile unsigned long long _m2 = (unsigned long long)__readgsqword(0x60); \
        volatile unsigned long long _m3 = (unsigned long long)__readgsqword(0x30); \
        volatile unsigned long long _m4 = _m1 ^ _m2 ^ _m3; \
        volatile unsigned long long _m5 = (_m1 + _m2) ^ _m3; \
 \
        if (((_m1 ^ (_m1 ^ _m1)) == _m1) && ((_m2 | 0) == _m2) && ((_m3 & ~_m3) == 0)) { \
            volatile int _pre_branch = (_m1 ^ _m2 ^ _m3) & 0x3F; \
            for (volatile int _pre_iter = 0; _pre_iter < 1; _pre_iter++) { \
                if (_pre_branch < 16) { \
                    if (_pre_branch & 1) { \
                        _m1 = (_m1 << 5) | (_m1 >> 59); \
                        if (_m1 & 0x10) { _m1 ^= _m4; if (_m1 & 0x20) _m1 = ~_m1; } \
                    } else { \
                        _m1 = ~_m1; \
                        if (_m1 & 0x40) { _m1 += _m5; if (_m1 & 0x80) _m1 ^= _m2; } \
                    } \
                    if (_pre_branch & 2) { \
                        _m2 = (_m2 << 7) | (_m2 >> 57); \
                        if (_m2 & 0x100) { _m2 ^= _m3; if (_m2 & 0x200) _m2 = ~_m2; } \
                    } else { \
                        _m2 = ~_m2; \
                        if (_m2 & 0x400) { _m2 += _m4; if (_m2 & 0x800) _m2 ^= _m1; } \
                    } \
                } else if (_pre_branch < 32) { \
                    if (_pre_branch & 4) { \
                        _m3 = (_m3 << 11) | (_m3 >> 53); \
                        if (_m3 & 0x1000) { _m3 ^= _m5; if (_m3 & 0x2000) _m3 = ~_m3; } \
                    } else { \
                        _m3 = ~_m3; \
                        if (_m3 & 0x4000) { _m3 += _m1; if (_m3 & 0x8000) _m3 ^= _m2; } \
                    } \
                    if (_pre_branch & 8) { \
                        _m4 = (_m4 << 13) | (_m4 >> 51); \
                        if (_m4 & 0x10000) { _m4 ^= _m1; if (_m4 & 0x20000) _m4 = ~_m4; } \
                    } else { \
                        _m4 = ~_m4; \
                        if (_m4 & 0x40000) { _m4 += _m2; if (_m4 & 0x80000) _m4 ^= _m3; } \
                    } \
                } else { \
                    if (_pre_branch & 0x10) { \
                        _m5 = (_m5 << 17) | (_m5 >> 47); \
                        if (_m5 & 0x100000) { _m5 ^= _m2; if (_m5 & 0x200000) _m5 = ~_m5; } \
                    } else { \
                        _m5 = ~_m5; \
                        if (_m5 & 0x400000) { _m5 += _m3; if (_m5 & 0x800000) _m5 ^= _m4; } \
                    } \
                    if (_pre_branch & 0x20) { \
                        _m1 = (_m1 << 19) | (_m1 >> 45); \
                        if (_m1 & 0x1000000) { _m1 ^= _m5; if (_m1 & 0x2000000) _m1 = ~_m1; } \
                    } else { \
                        _m1 = ~_m1; \
                        if (_m1 & 0x4000000) { _m1 += _m4; if (_m1 & 0x8000000) _m1 ^= __rdtsc(); } \
                    } \
                } \
            } \
        } \
 \
        if (((_m1 | ~_m1) == ~0ULL) && ((_m2 & 0) == 0)) { \
 \
            volatile int _vmp_state = 0; \
            for (volatile int _vmp_iter = 0; _vmp_iter < 1; _vmp_iter++) { \
                if (_m1 > _m2) { \
                    _m1 ^= _m2; \
                    _m1 = (_m1 << 13) | (_m1 >> 51); \
 \
                    if (((_m1 * 2) >> 1) == _m1) { \
                        if (_m1 & 0x1000) { \
                            _m1 ^= _m3; \
                            _m1 = ~_m1; \
 \
                            if ((_m1 ^ (_m1 >> 32)) & 0xFF) { \
                                _vmp_state = 1; \
                            } \
                        } else { \
                            _m1 += _m3; \
                            _vmp_state = 2; \
                        } \
                    } \
                } else { \
                    _m2 ^= _m1; \
                    _m2 = (_m2 << 17) | (_m2 >> 47); \
                    if (_m2 & 0x2000) { \
                        _m2 ^= __rdtsc(); \
                        _vmp_state = 3; \
                    } \
                } \
            } \
 \
            if (((_m1 & _m2) ^ (_m1 & _m2)) != 0) { \
                _m1 = 0xDEADC0DE; \
                _m2 = 0xBADF00D; \
            } \
        } \
        volatile unsigned long long _bdg = _m1 ^ _m2 ^ _m3 ^ _m4 ^ _m5; \
        if (_bdg == 0) {  \
 \
        volatile int _dispatch_state = (_m1 ^ _m2) & 0x1F; \
        volatile int _dispatch_done = 0; \
        while (!_dispatch_done) { \
 \
            if (((_dispatch_state | 0) == _dispatch_state) || ((_dispatch_state & ~0) == 0)) { \
                switch (_dispatch_state) { \
                    case 0: \
                        _m3 ^= 0xDEADBEEF; \
                        if ((_m3 ^ 0) == _m3) { _dispatch_done = 1; } \
                        break; \
                    case 1: \
                        _m3 = ~_m3; \
 \
                        for (volatile int _k = 0; _k < (((_m3 & 1) == 0) ? 0 : 1); _k++) { \
                            _m3 ^= __rdtsc(); \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 2: \
                        _m3 = (_m3 << 7) | (_m3 >> 57); \
                        if (((_m3 | ~_m3) == ~0ULL)) { _dispatch_done = 1; } \
                        break; \
                    case 3: \
                        _m3 += _m1; \
 \
                        if ((_m3 ^ (_m3 >> 16)) & 0xFFFF) { \
                            _m3 = (_m3 << 11) | (_m3 >> 53); \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 4: \
                        _m3 ^= _m2; \
                        if (((_m3 * 2) >> 1) == _m3) { _dispatch_done = 1; } \
                        break; \
                    case 5: \
                        _m3 = (_m3 << 11) | (_m3 >> 53); \
                        _dispatch_done = 1; \
                        break; \
                    case 6: \
                        _m3 -= _m1; \
 \
                        if (((_m3 & 0) == 0) && ((_m3 | 0) == _m3)) { \
                            _m3 = ~_m3; \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 7: \
                        _m3 ^= __rdtsc(); \
                        _dispatch_done = 1; \
                        break; \
                    case 8: \
                        _m3 = (_m3 << 19) | (_m3 >> 45); \
                        if ((_m3 ^ (_m3 >> 24)) & 0xFF) { \
                            _m3 += _m2; \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 9: \
                        _m3 += _m2; \
                        _dispatch_done = 1; \
                        break; \
                    case 10: \
                        _m3 = ~_m3 ^ _m1; \
 \
                        for (volatile int _j = 0; _j < (((_m3 & 2) == 0) ? 0 : 1); _j++) { \
                            _m3 = (_m3 << 13) | (_m3 >> 51); \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 11: \
                        _m3 = (_m3 << 23) | (_m3 >> 41); \
                        _dispatch_done = 1; \
                        break; \
                    case 12: \
                        _m3 ^= 0xCAFEBABE; \
                        if (((_m3 | ~_m3) == ~0ULL)) { _dispatch_done = 1; } \
                        break; \
                    case 13: \
                        _m3 *= (_m1 | 1); \
                        _dispatch_done = 1; \
                        break; \
                    case 14: \
                        _m3 = (_m3 << 29) | (_m3 >> 35); \
                        _dispatch_done = 1; \
                        break; \
                    case 15: \
                        _m3 ^= (unsigned long long)__readgsqword(0x60); \
                        _dispatch_done = 1; \
                        break; \
                    case 16: \
                        _m3 = (_m3 << 5) | (_m3 >> 59); \
                        if ((_m3 ^ (_m3 >> 8)) & 0xFF) { \
                            _m3 += __rdtsc(); \
                        } \
                        _dispatch_done = 1; \
                        break; \
                    case 17: \
                        _m3 += __rdtsc(); \
                        _dispatch_done = 1; \
                        break; \
                    case 18: \
                        _m3 = ~_m3 + _m2; \
                        _dispatch_done = 1; \
                        break; \
                    case 19: \
                        _m3 = (_m3 << 15) | (_m3 >> 49); \
                        _dispatch_done = 1; \
                        break; \
                    case 20: \
                        _m3 ^= 0xFEEDFACE; \
                        _dispatch_done = 1; \
                        break; \
                    case 21: \
                        _m3 -= _m2; \
                        _dispatch_done = 1; \
                        break; \
                    case 22: \
                        _m3 = (_m3 << 27) | (_m3 >> 37); \
                        _dispatch_done = 1; \
                        break; \
                    case 23: \
                        _m3 ^= (unsigned long long)__readgsqword(0x30); \
                        _dispatch_done = 1; \
                        break; \
                    case 24: \
                        _m3 = ~_m3; \
                        _dispatch_done = 1; \
                        break; \
                    case 25: \
                        _m3 = (_m3 << 9) | (_m3 >> 55); \
                        _dispatch_done = 1; \
                        break; \
                    case 26: \
                        _m3 += _m1 + _m2; \
                        _dispatch_done = 1; \
                        break; \
                    case 27: \
                        _m3 = (_m3 << 21) | (_m3 >> 43); \
                        _dispatch_done = 1; \
                        break; \
                    case 28: \
                        _m3 ^= __rdtsc() ^ _m1; \
                        _dispatch_done = 1; \
                        break; \
                    case 29: \
                        _m3 = (_m3 << 31) | (_m3 >> 33); \
                        _dispatch_done = 1; \
                        break; \
                    case 30: \
                        _m3 = ~_m3 ^ _m2; \
                        _dispatch_done = 1; \
                        break; \
                    default: \
                        _m3 ^= 0xDEADC0DE; \
                        _dispatch_done = 1; \
                        break; \
                } \
            } \
        } \
        volatile unsigned long long _final = _m1 ^ _m2 ^ _m3; \
 \
        if (((_final | ~_final) == ~0ULL) && (((_final & 0xFF) < 0x80) || ((_final & 0xFF) >= 0x80))) { \
            if ((_final & 0xFF) < 0x80) { \
                _final = ~_final; \
 \
                for (volatile int _i = 0; _i < (((_final & 0x100) == 0) ? 0 : 1); _i++) { \
                    if (_final & 0x100) { \
                        _final ^= __rdtsc(); \
                        if (_final & 0x10000) { \
                            _final = (_final << 7) | (_final >> 57); \
                            if (_final > _m1) { _final += _m2; } else { _final ^= _m3; } \
                        } else { \
                            _final = ~_final; \
                            if (_final < _m2) { _final ^= _m4; } else { _final += _m5; } \
                        } \
                    } \
                } \
            } else { \
                _final = (_final << 11) | (_final >> 53); \
                if (((_final * 2) >> 1) == _final) { \
                    if (_final & 0x200) { \
                        _final ^= (unsigned long long)__readgsqword(0x60); \
                        if (_final & 0x20000) { \
                            _final = (_final << 13) | (_final >> 51); \
                            if (_final > _m3) { _final += _m4; } else { _final ^= _m5; } \
                        } else { \
                            _final = ~_final; \
                            if (_final < _m1) { _final ^= __rdtsc(); } else { _final += _m2; } \
                        } \
                    } \
                } \
            } \
        } \
 \
        for (volatile int _maze1 = 0; _maze1 < (((_final & 0x4) == 0x4) ? 1 : 1); _maze1++) { \
            if (_final & 0x40000) { \
                _final = (_final << 17) | (_final >> 47); \
                for (volatile int _maze2 = 0; _maze2 < (((_final & 0x8) == 0x8) ? 1 : 1); _maze2++) { \
                    if (_final > _m1) { \
                        _final ^= _m2; \
                        if (_final & 0x80000) { \
                            _final = (_final << 19) | (_final >> 45); \
                            for (volatile int _maze3 = 0; _maze3 < (((_final & 0x10) == 0x10) ? 1 : 1); _maze3++) { \
                                if (_final & 0x100000) { \
                                    _final ^= __rdtsc(); \
                                    if (_final > _m3) { _final += _m4; } else { _final ^= _m5; } \
                                } else { \
                                    _final = ~_final; \
                                    if (_final < _m2) { _final += _m1; } else { _final ^= _m3; } \
                                } \
                            } \
                        } else { \
                            _final = ~_final; \
                            if (_final & 0x200000) { _final ^= _m3; } else { _final += _m4; } \
                        } \
                    } else { \
                        _final += _m5; \
                        if (_final & 0x400000) { \
                            _final = (_final << 23) | (_final >> 41); \
                            if (_final & 0x800000) { _final ^= _m1; } else { _final += _m2; } \
                        } else { \
                            _final = ~_final; \
                            if (_final & 0x1000000) { _final ^= __rdtsc(); } else { _final += _m3; } \
                        } \
                    } \
                } \
            } else { \
                _final = ~_final; \
                if (_final & 0x2000000) { \
                    _final = (_final << 29) | (_final >> 35); \
                    if (_final > _m4) { _final ^= _m5; } else { _final += _m1; } \
                } else { \
                    _final ^= _m2; \
                    if (_final < _m3) { _final += __rdtsc(); } else { _final = ~_final; } \
                } \
            } \
        } \
 \
        volatile int _final_state = (_final ^ _m1 ^ _m2 ^ _m3) & 0x3F; \
        volatile int _final_done = 0; \
        while (!_final_done) { \
            if (((_final_state | 0) == _final_state) && ((_final_state & ~0) == 0)) { \
                switch (_final_state) { \
                    case 0: _final ^= 0xDEADBEEF; if (_final & 1) _final = ~_final; _final_done = 1; break; \
                    case 1: _final = (_final << 3) | (_final >> 61); if (_final & 2) _final += _m1; _final_done = 1; break; \
                    case 2: _final += _m2; if (_final & 4) _final ^= _m3; _final_done = 1; break; \
                    case 3: _final = ~_final; if (_final & 8) _final = (_final << 7) | (_final >> 57); _final_done = 1; break; \
                    case 4: _final ^= _m4; if (_final & 0x10) _final += _m5; _final_done = 1; break; \
                    case 5: _final = (_final << 11) | (_final >> 53); if (_final & 0x20) _final = ~_final; _final_done = 1; break; \
                    case 6: _final -= _m1; if (_final & 0x40) _final ^= _m2; _final_done = 1; break; \
                    case 7: _final ^= __rdtsc(); if (_final & 0x80) _final += _m3; _final_done = 1; break; \
                    case 8: _final = (_final << 13) | (_final >> 51); if (_final & 0x100) _final = ~_final; _final_done = 1; break; \
                    case 9: _final += _m5; if (_final & 0x200) _final ^= _m4; _final_done = 1; break; \
                    case 10: _final = ~_final; if (_final & 0x400) _final = (_final << 17) | (_final >> 47); _final_done = 1; break; \
                    case 11: _final ^= _m1; if (_final & 0x800) _final += _m2; _final_done = 1; break; \
                    case 12: _final = (_final << 19) | (_final >> 45); if (_final & 0x1000) _final ^= _m3; _final_done = 1; break; \
                    case 13: _final += _m3; if (_final & 0x2000) _final = ~_final; _final_done = 1; break; \
                    case 14: _final = ~_final; if (_final & 0x4000) _final ^= __rdtsc(); _final_done = 1; break; \
                    case 15: _final ^= _m4; if (_final & 0x8000) _final += _m5; _final_done = 1; break; \
                    case 16: _final = (_final << 23) | (_final >> 41); if (_final & 0x10000) _final = ~_final; _final_done = 1; break; \
                    case 17: _final += _m1; if (_final & 0x20000) _final ^= _m2; _final_done = 1; break; \
                    case 18: _final = ~_final; if (_final & 0x40000) _final = (_final << 29) | (_final >> 35); _final_done = 1; break; \
                    case 19: _final ^= _m5; if (_final & 0x80000) _final += _m3; _final_done = 1; break; \
                    case 20: _final = (_final << 31) | (_final >> 33); if (_final & 0x100000) _final ^= _m4; _final_done = 1; break; \
                    case 21: _final += _m4; if (_final & 0x200000) _final = ~_final; _final_done = 1; break; \
                    case 22: _final = ~_final; if (_final & 0x400000) _final ^= _m1; _final_done = 1; break; \
                    case 23: _final ^= _m2; if (_final & 0x800000) _final += __rdtsc(); _final_done = 1; break; \
                    case 24: _final = (_final << 5) | (_final >> 59); if (_final & 0x1000000) _final = ~_final; _final_done = 1; break; \
                    case 25: _final += _m5; if (_final & 0x2000000) _final ^= _m3; _final_done = 1; break; \
                    case 26: _final = ~_final; if (_final & 0x4000000) _final = (_final << 9) | (_final >> 55); _final_done = 1; break; \
                    case 27: _final ^= _m4; if (_final & 0x8000000) _final += _m1; _final_done = 1; break; \
                    case 28: _final = (_final << 15) | (_final >> 49); if (_final & 0x10000000) _final ^= _m2; _final_done = 1; break; \
                    case 29: _final += _m2; if (_final & 0x20000000) _final = ~_final; _final_done = 1; break; \
                    case 30: _final = ~_final; if (_final & 0x40000000) _final ^= _m5; _final_done = 1; break; \
                    case 31: _final ^= _m3; if (_final & 0x80000000ULL) _final += __rdtsc(); _final_done = 1; break; \
                    case 32: _final = (_final << 21) | (_final >> 43); if (_final & 0x100000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 33: _final += _m1; if (_final & 0x200000000ULL) _final ^= _m4; _final_done = 1; break; \
                    case 34: _final = ~_final; if (_final & 0x400000000ULL) _final = (_final << 27) | (_final >> 37); _final_done = 1; break; \
                    case 35: _final ^= _m5; if (_final & 0x800000000ULL) _final += _m2; _final_done = 1; break; \
                    case 36: _final = (_final << 25) | (_final >> 39); if (_final & 0x1000000000ULL) _final ^= _m3; _final_done = 1; break; \
                    case 37: _final += _m3; if (_final & 0x2000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 38: _final = ~_final; if (_final & 0x4000000000ULL) _final ^= _m1; _final_done = 1; break; \
                    case 39: _final ^= _m4; if (_final & 0x8000000000ULL) _final += __rdtsc(); _final_done = 1; break; \
                    case 40: _final = (_final << 11) | (_final >> 53); if (_final & 0x10000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 41: _final += _m5; if (_final & 0x20000000000ULL) _final ^= _m2; _final_done = 1; break; \
                    case 42: _final = ~_final; if (_final & 0x40000000000ULL) _final = (_final << 13) | (_final >> 51); _final_done = 1; break; \
                    case 43: _final ^= _m1; if (_final & 0x80000000000ULL) _final += _m3; _final_done = 1; break; \
                    case 44: _final = (_final << 17) | (_final >> 47); if (_final & 0x100000000000ULL) _final ^= _m4; _final_done = 1; break; \
                    case 45: _final += _m4; if (_final & 0x200000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 46: _final = ~_final; if (_final & 0x400000000000ULL) _final ^= _m5; _final_done = 1; break; \
                    case 47: _final ^= _m2; if (_final & 0x800000000000ULL) _final += __rdtsc(); _final_done = 1; break; \
                    case 48: _final = (_final << 19) | (_final >> 45); if (_final & 0x1000000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 49: _final += _m1; if (_final & 0x2000000000000ULL) _final ^= _m3; _final_done = 1; break; \
                    case 50: _final = ~_final; if (_final & 0x4000000000000ULL) _final = (_final << 23) | (_final >> 41); _final_done = 1; break; \
                    case 51: _final ^= _m5; if (_final & 0x8000000000000ULL) _final += _m4; _final_done = 1; break; \
                    case 52: _final = (_final << 29) | (_final >> 35); if (_final & 0x10000000000000ULL) _final ^= _m1; _final_done = 1; break; \
                    case 53: _final += _m2; if (_final & 0x20000000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 54: _final = ~_final; if (_final & 0x40000000000000ULL) _final ^= _m3; _final_done = 1; break; \
                    case 55: _final ^= _m4; if (_final & 0x80000000000000ULL) _final += __rdtsc(); _final_done = 1; break; \
                    case 56: _final = (_final << 31) | (_final >> 33); if (_final & 0x100000000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 57: _final += _m5; if (_final & 0x200000000000000ULL) _final ^= _m1; _final_done = 1; break; \
                    case 58: _final = ~_final; if (_final & 0x400000000000000ULL) _final = (_final << 5) | (_final >> 59); _final_done = 1; break; \
                    case 59: _final ^= _m2; if (_final & 0x800000000000000ULL) _final += _m3; _final_done = 1; break; \
                    case 60: _final = (_final << 7) | (_final >> 57); if (_final & 0x1000000000000000ULL) _final ^= _m4; _final_done = 1; break; \
                    case 61: _final += _m3; if (_final & 0x2000000000000000ULL) _final = ~_final; _final_done = 1; break; \
                    case 62: _final = ~_final; if (_final & 0x4000000000000000ULL) _final ^= _m5; _final_done = 1; break; \
                    default: _final ^= __rdtsc(); if (_final & 0x8000000000000000ULL) _final += _m1; _final_done = 1; break; \
                } \
            } else { \
                _final_done = 1; \
            } \
        } \
 \
        if (((_final ^ _final) != 0) || ((_final & ~_final) != 0)) { \
            _final = 0xBADC0DE; \
        } \
    } } while (0)

#define MBA_XOR(x, y) (((x) + (y)) - (((x) & (y)) << 1))
#define MBA_AND(x, y) (((x) + (y)) - ((x) | (y)))
#define MBA_OR(x, y) (((x) + (y)) - ((x) & (y)))
#define MBA_ADD(x, y) (((x) ^ (y)) + (((x) & (y)) << 1))
#define MBA_SUB(x, y) (((x) ^ (y)) - (((~(x)) & (y)) << 1))
#define MBA_NOT(x) (~(x))
#define MBA_NEG(x) ((~(x)) + 1)

#define GRAPH_NODE_XOR 0
#define GRAPH_NODE_ADD 1
#define GRAPH_NODE_ROL 2
#define GRAPH_NODE_ROR 3
#define GRAPH_NODE_NOT 4
#define GRAPH_NODE_MUL 5
#define GRAPH_NODE_SUB 6
#define GRAPH_NODE_SWAP 7
#define GRAPH_NODE_MBA_XOR 8
#define GRAPH_NODE_MBA_AND 9
#define GRAPH_NODE_MBA_OR 10
#define GRAPH_NODE_MBA_ADD 11
#define GRAPH_NODE_RDTSC 12
#define GRAPH_NODE_GSREAD 13
#define GRAPH_NODE_NESTED 14
#define GRAPH_NODE_BRANCH 15

#define EDGE_WEIGHT_HIGH 0x7
#define EDGE_WEIGHT_MED 0x3
#define EDGE_WEIGHT_LOW 0x1

#define GRAPH_POLYMORPHIC_LAYER_1(state, v1, v2, v3, v4) \
    do { \
        volatile int _node = (state) & 0x7F; \
        volatile unsigned long long _temp1 = v1; \
        volatile unsigned long long _temp2 = v2; \
        volatile unsigned long long _temp3 = v3; \
        volatile unsigned long long _temp4 = v4; \
 \
        switch (_node) { \
            case 0: v1 = MBA_XOR(_temp1, _temp2); if (v1 & 1) v1 = MBA_ADD(v1, _temp3); break; \
            case 1: v1 = MBA_ADD(_temp1, _temp2); if (v1 & 2) v1 = MBA_XOR(v1, _temp4); break; \
            case 2: v1 = (v1 << 7) | (v1 >> 57); if (v1 & 4) v1 = MBA_OR(v1, _temp3); break; \
            case 3: v1 = MBA_NOT(_temp1); if (v1 & 8) v1 = MBA_AND(v1, _temp2); break; \
            case 4: v1 = MBA_SUB(_temp1, _temp2); if (v1 & 0x10) v1 ^= _temp3; break; \
            case 5: v1 = (v1 << 11) | (v1 >> 53); if (v1 & 0x20) v1 = MBA_ADD(v1, _temp4); break; \
            case 6: v1 = MBA_OR(_temp1, _temp2); if (v1 & 0x40) v1 = MBA_XOR(v1, _temp3); break; \
            case 7: v1 = MBA_AND(_temp1, _temp2); if (v1 & 0x80) v1 += _temp4; break; \
            case 8: v1 = (v1 << 13) | (v1 >> 51); if (v1 & 0x100) v1 = MBA_NOT(v1); break; \
            case 9: v1 = MBA_XOR(_temp1, _temp3); if (v1 & 0x200) v1 = MBA_SUB(v1, _temp2); break; \
            case 10: v1 = (v1 << 17) | (v1 >> 47); if (v1 & 0x400) v1 = MBA_OR(v1, _temp4); break; \
            case 11: v1 = MBA_ADD(_temp1, _temp3); if (v1 & 0x800) v1 ^= _temp2; break; \
            case 12: v1 = (v1 << 19) | (v1 >> 45); if (v1 & 0x1000) v1 = MBA_AND(v1, _temp3); break; \
            case 13: v1 = MBA_SUB(_temp1, _temp3); if (v1 & 0x2000) v1 = MBA_XOR(v1, _temp4); break; \
            case 14: v1 = (v1 << 23) | (v1 >> 41); if (v1 & 0x4000) v1 = MBA_ADD(v1, _temp2); break; \
            case 15: v1 = MBA_NOT(_temp2); if (v1 & 0x8000) v1 = MBA_OR(v1, _temp3); break; \
            case 16: v1 = (v1 << 29) | (v1 >> 35); if (v1 & 0x10000) v1 ^= _temp4; break; \
            case 17: v1 = MBA_XOR(_temp2, _temp3); if (v1 & 0x20000) v1 = MBA_AND(v1, _temp1); break; \
            case 18: v1 = (v1 << 31) | (v1 >> 33); if (v1 & 0x40000) v1 = MBA_SUB(v1, _temp4); break; \
            case 19: v1 = MBA_ADD(_temp2, _temp3); if (v1 & 0x80000) v1 = MBA_NOT(v1); break; \
            case 20: v1 = (v1 << 5) | (v1 >> 59); if (v1 & 0x100000) v1 = MBA_XOR(v1, _temp1); break; \
            case 21: v1 = MBA_OR(_temp2, _temp3); if (v1 & 0x200000) v1 += _temp4; break; \
            case 22: v1 = (v1 << 9) | (v1 >> 55); if (v1 & 0x400000) v1 = MBA_AND(v1, _temp1); break; \
            case 23: v1 = MBA_SUB(_temp2, _temp3); if (v1 & 0x800000) v1 = MBA_OR(v1, _temp4); break; \
            case 24: v1 = (v1 << 15) | (v1 >> 49); if (v1 & 0x1000000) v1 ^= _temp1; break; \
            case 25: v1 = MBA_XOR(_temp2, _temp4); if (v1 & 0x2000000) v1 = MBA_ADD(v1, _temp3); break; \
            case 26: v1 = (v1 << 21) | (v1 >> 43); if (v1 & 0x4000000) v1 = MBA_NOT(v1); break; \
            case 27: v1 = MBA_AND(_temp2, _temp4); if (v1 & 0x8000000) v1 = MBA_SUB(v1, _temp1); break; \
            case 28: v1 = (v1 << 25) | (v1 >> 39); if (v1 & 0x10000000) v1 = MBA_XOR(v1, _temp3); break; \
            case 29: v1 = MBA_ADD(_temp2, _temp4); if (v1 & 0x20000000) v1 = MBA_OR(v1, _temp1); break; \
            case 30: v1 = (v1 << 27) | (v1 >> 37); if (v1 & 0x40000000) v1 ^= _temp3; break; \
            case 31: v1 = MBA_OR(_temp2, _temp4); if (v1 & 0x80000000ULL) v1 = MBA_AND(v1, _temp1); break; \
            case 32: v1 = MBA_NOT(_temp3); if (v1 & 0x100000000ULL) v1 = MBA_XOR(v1, _temp2); break; \
            case 33: v1 = (v1 << 3) | (v1 >> 61); if (v1 & 0x200000000ULL) v1 = MBA_ADD(v1, _temp4); break; \
            case 34: v1 = MBA_XOR(_temp3, _temp4); if (v1 & 0x400000000ULL) v1 = MBA_SUB(v1, _temp1); break; \
            case 35: v1 = (v1 << 7) | (v1 >> 57); if (v1 & 0x800000000ULL) v1 = MBA_OR(v1, _temp2); break; \
            case 36: v1 = MBA_SUB(_temp3, _temp4); if (v1 & 0x1000000000ULL) v1 ^= _temp1; break; \
            case 37: v1 = (v1 << 11) | (v1 >> 53); if (v1 & 0x2000000000ULL) v1 = MBA_AND(v1, _temp2); break; \
            case 38: v1 = MBA_ADD(_temp3, _temp4); if (v1 & 0x4000000000ULL) v1 = MBA_NOT(v1); break; \
            case 39: v1 = (v1 << 13) | (v1 >> 51); if (v1 & 0x8000000000ULL) v1 = MBA_XOR(v1, _temp1); break; \
            case 40: v1 = MBA_AND(_temp3, _temp4); if (v1 & 0x10000000000ULL) v1 = MBA_OR(v1, _temp2); break; \
            case 41: v1 = (v1 << 17) | (v1 >> 47); if (v1 & 0x20000000000ULL) v1 += _temp1; break; \
            case 42: v1 = MBA_OR(_temp3, _temp4); if (v1 & 0x40000000000ULL) v1 = MBA_SUB(v1, _temp2); break; \
            case 43: v1 = (v1 << 19) | (v1 >> 45); if (v1 & 0x80000000000ULL) v1 = MBA_XOR(v1, _temp1); break; \
            case 44: v1 = MBA_XOR(_temp1, _temp4); if (v1 & 0x100000000000ULL) v1 = MBA_AND(v1, _temp3); break; \
            case 45: v1 = (v1 << 23) | (v1 >> 41); if (v1 & 0x200000000000ULL) v1 = MBA_NOT(v1); break; \
            case 46: v1 = MBA_SUB(_temp1, _temp4); if (v1 & 0x400000000000ULL) v1 ^= _temp2; break; \
            case 47: v1 = (v1 << 29) | (v1 >> 35); if (v1 & 0x800000000000ULL) v1 = MBA_OR(v1, _temp3); break; \
            case 48: v1 = MBA_ADD(_temp1, _temp4); if (v1 & 0x1000000000000ULL) v1 = MBA_XOR(v1, _temp2); break; \
            case 49: v1 = (v1 << 31) | (v1 >> 33); if (v1 & 0x2000000000000ULL) v1 = MBA_AND(v1, _temp3); break; \
            case 50: v1 = MBA_NOT(_temp4); if (v1 & 0x4000000000000ULL) v1 = MBA_SUB(v1, _temp1); break; \
            case 51: v1 = (v1 << 5) | (v1 >> 59); if (v1 & 0x8000000000000ULL) v1 = MBA_OR(v1, _temp2); break; \
            case 52: v1 = MBA_AND(_temp1, _temp4); if (v1 & 0x10000000000000ULL) v1 ^= _temp3; break; \
            case 53: v1 = (v1 << 9) | (v1 >> 55); if (v1 & 0x20000000000000ULL) v1 = MBA_XOR(v1, _temp2); break; \
            case 54: v1 = MBA_OR(_temp1, _temp4); if (v1 & 0x40000000000000ULL) v1 = MBA_ADD(v1, _temp3); break; \
            case 55: v1 = (v1 << 15) | (v1 >> 49); if (v1 & 0x80000000000000ULL) v1 = MBA_NOT(v1); break; \
            case 56: v1 = MBA_XOR(MBA_ADD(_temp1, _temp2), MBA_OR(_temp3, _temp4)); break; \
            case 57: v1 = MBA_AND(MBA_SUB(_temp1, _temp2), MBA_XOR(_temp3, _temp4)); break; \
            case 58: v1 = MBA_OR(MBA_NOT(_temp1), MBA_AND(_temp2, _temp3)); break; \
            case 59: v1 = MBA_ADD(MBA_XOR(_temp1, _temp2), MBA_SUB(_temp3, _temp4)); break; \
            case 60: v1 = MBA_SUB(MBA_OR(_temp1, _temp2), MBA_AND(_temp3, _temp4)); break; \
            case 61: v1 = MBA_XOR(MBA_NOT(_temp1), MBA_ADD(_temp2, _temp3)); break; \
            case 62: v1 = MBA_AND(MBA_XOR(_temp1, _temp2), MBA_OR(_temp3, _temp4)); break; \
            case 63: v1 = MBA_OR(MBA_ADD(_temp1, _temp2), MBA_SUB(_temp3, _temp4)); break; \
            case 64: v2 = MBA_XOR(_temp2, _temp1); if (v2 & 1) v2 = MBA_ADD(v2, _temp4); break; \
            case 65: v2 = MBA_ADD(_temp2, _temp1); if (v2 & 2) v2 = MBA_OR(v2, _temp3); break; \
            case 66: v2 = (v2 << 7) | (v2 >> 57); if (v2 & 4) v2 = MBA_AND(v2, _temp4); break; \
            case 67: v2 = MBA_NOT(_temp2); if (v2 & 8) v2 = MBA_SUB(v2, _temp1); break; \
            case 68: v2 = MBA_SUB(_temp2, _temp1); if (v2 & 0x10) v2 ^= _temp4; break; \
            case 69: v2 = (v2 << 11) | (v2 >> 53); if (v2 & 0x20) v2 = MBA_XOR(v2, _temp3); break; \
            case 70: v2 = MBA_OR(_temp2, _temp1); if (v2 & 0x40) v2 = MBA_AND(v2, _temp4); break; \
            case 71: v2 = MBA_AND(_temp2, _temp1); if (v2 & 0x80) v2 += _temp3; break; \
            case 72: v2 = (v2 << 13) | (v2 >> 51); if (v2 & 0x100) v2 = MBA_NOT(v2); break; \
            case 73: v2 = MBA_XOR(_temp2, _temp4); if (v2 & 0x200) v2 = MBA_ADD(v2, _temp1); break; \
            case 74: v2 = (v2 << 17) | (v2 >> 47); if (v2 & 0x400) v2 = MBA_SUB(v2, _temp3); break; \
            case 75: v2 = MBA_ADD(_temp2, _temp4); if (v2 & 0x800) v2 ^= _temp1; break; \
            case 76: v2 = (v2 << 19) | (v2 >> 45); if (v2 & 0x1000) v2 = MBA_OR(v2, _temp3); break; \
            case 77: v2 = MBA_SUB(_temp2, _temp4); if (v2 & 0x2000) v2 = MBA_XOR(v2, _temp1); break; \
            case 78: v2 = (v2 << 23) | (v2 >> 41); if (v2 & 0x4000) v2 = MBA_AND(v2, _temp3); break; \
            case 79: v2 = MBA_NOT(_temp1); if (v2 & 0x8000) v2 = MBA_ADD(v2, _temp4); break; \
            case 80: v3 = MBA_XOR(_temp3, _temp1); if (v3 & 1) v3 = MBA_OR(v3, _temp2); break; \
            case 81: v3 = MBA_ADD(_temp3, _temp1); if (v3 & 2) v3 = MBA_AND(v3, _temp4); break; \
            case 82: v3 = (v3 << 7) | (v3 >> 57); if (v3 & 4) v3 = MBA_SUB(v3, _temp2); break; \
            case 83: v3 = MBA_NOT(_temp3); if (v3 & 8) v3 = MBA_XOR(v3, _temp1); break; \
            case 84: v3 = MBA_SUB(_temp3, _temp1); if (v3 & 0x10) v3 ^= _temp2; break; \
            case 85: v3 = (v3 << 11) | (v3 >> 53); if (v3 & 0x20) v3 = MBA_ADD(v3, _temp4); break; \
            case 86: v3 = MBA_OR(_temp3, _temp1); if (v3 & 0x40) v3 = MBA_AND(v3, _temp2); break; \
            case 87: v3 = MBA_AND(_temp3, _temp1); if (v3 & 0x80) v3 += _temp4; break; \
            case 88: v3 = (v3 << 13) | (v3 >> 51); if (v3 & 0x100) v3 = MBA_NOT(v3); break; \
            case 89: v3 = MBA_XOR(_temp3, _temp2); if (v3 & 0x200) v3 = MBA_OR(v3, _temp1); break; \
            case 90: v3 = (v3 << 17) | (v3 >> 47); if (v3 & 0x400) v3 = MBA_SUB(v3, _temp4); break; \
            case 91: v3 = MBA_ADD(_temp3, _temp2); if (v3 & 0x800) v3 ^= _temp1; break; \
            case 92: v3 = (v3 << 19) | (v3 >> 45); if (v3 & 0x1000) v3 = MBA_AND(v3, _temp4); break; \
            case 93: v3 = MBA_SUB(_temp3, _temp2); if (v3 & 0x2000) v3 = MBA_XOR(v3, _temp1); break; \
            case 94: v3 = (v3 << 23) | (v3 >> 41); if (v3 & 0x4000) v3 = MBA_OR(v3, _temp4); break; \
            case 95: v3 = MBA_NOT(_temp2); if (v3 & 0x8000) v3 = MBA_ADD(v3, _temp1); break; \
            case 96: v4 = MBA_XOR(_temp4, _temp1); if (v4 & 1) v4 = MBA_AND(v4, _temp2); break; \
            case 97: v4 = MBA_ADD(_temp4, _temp1); if (v4 & 2) v4 = MBA_OR(v4, _temp3); break; \
            case 98: v4 = (v4 << 7) | (v4 >> 57); if (v4 & 4) v4 = MBA_SUB(v4, _temp2); break; \
            case 99: v4 = MBA_NOT(_temp4); if (v4 & 8) v4 = MBA_XOR(v4, _temp1); break; \
            case 100: v4 = MBA_SUB(_temp4, _temp1); if (v4 & 0x10) v4 ^= _temp3; break; \
            case 101: v4 = (v4 << 11) | (v4 >> 53); if (v4 & 0x20) v4 = MBA_ADD(v4, _temp2); break; \
            case 102: v4 = MBA_OR(_temp4, _temp1); if (v4 & 0x40) v4 = MBA_AND(v4, _temp3); break; \
            case 103: v4 = MBA_AND(_temp4, _temp1); if (v4 & 0x80) v4 += _temp2; break; \
            case 104: v4 = (v4 << 13) | (v4 >> 51); if (v4 & 0x100) v4 = MBA_NOT(v4); break; \
            case 105: v4 = MBA_XOR(_temp4, _temp3); if (v4 & 0x200) v4 = MBA_OR(v4, _temp1); break; \
            case 106: v4 = (v4 << 17) | (v4 >> 47); if (v4 & 0x400) v4 = MBA_SUB(v4, _temp2); break; \
            case 107: v4 = MBA_ADD(_temp4, _temp3); if (v4 & 0x800) v4 ^= _temp1; break; \
            case 108: v4 = (v4 << 19) | (v4 >> 45); if (v4 & 0x1000) v4 = MBA_AND(v4, _temp2); break; \
            case 109: v4 = MBA_SUB(_temp4, _temp3); if (v4 & 0x2000) v4 = MBA_XOR(v4, _temp1); break; \
            case 110: v4 = (v4 << 23) | (v4 >> 41); if (v4 & 0x4000) v4 = MBA_OR(v4, _temp2); break; \
            case 111: v4 = MBA_NOT(_temp3); if (v4 & 0x8000) v4 = MBA_ADD(v4, _temp1); break; \
            case 112: v1 = MBA_XOR(MBA_AND(_temp1, _temp2), MBA_OR(_temp3, _temp4)); v1 = (v1 << 5) | (v1 >> 59); break; \
            case 113: v2 = MBA_ADD(MBA_OR(_temp1, _temp2), MBA_AND(_temp3, _temp4)); v2 = (v2 << 9) | (v2 >> 55); break; \
            case 114: v3 = MBA_SUB(MBA_XOR(_temp1, _temp2), MBA_ADD(_temp3, _temp4)); v3 = (v3 << 15) | (v3 >> 49); break; \
            case 115: v4 = MBA_OR(MBA_SUB(_temp1, _temp2), MBA_XOR(_temp3, _temp4)); v4 = (v4 << 21) | (v4 >> 43); break; \
            case 116: v1 = MBA_AND(MBA_ADD(_temp1, _temp2), MBA_NOT(_temp3)); v1 ^= _temp4; break; \
            case 117: v2 = MBA_NOT(MBA_OR(_temp1, _temp2)); v2 = MBA_XOR(v2, MBA_AND(_temp3, _temp4)); break; \
            case 118: v3 = MBA_XOR(MBA_SUB(_temp1, _temp2), MBA_OR(_temp3, _temp4)); v3 = (v3 << 27) | (v3 >> 37); break; \
            case 119: v4 = MBA_ADD(MBA_AND(_temp1, _temp2), MBA_SUB(_temp3, _temp4)); v4 = MBA_NOT(v4); break; \
            case 120: v1 = MBA_OR(MBA_NOT(_temp1), MBA_XOR(_temp2, _temp3)); v1 += _temp4; break; \
            case 121: v2 = MBA_SUB(MBA_XOR(_temp1, _temp2), MBA_OR(_temp3, _temp4)); v2 = (v2 << 31) | (v2 >> 33); break; \
            case 122: v3 = MBA_AND(MBA_ADD(_temp1, _temp2), MBA_NOT(_temp4)); v3 ^= _temp3; break; \
            case 123: v4 = MBA_XOR(MBA_OR(_temp1, _temp2), MBA_AND(_temp3, _temp4)); v4 = MBA_NOT(v4); break; \
            case 124: v1 = MBA_ADD(MBA_NOT(_temp1), MBA_SUB(_temp2, _temp3)); v1 = MBA_XOR(v1, _temp4); break; \
            case 125: v2 = MBA_OR(MBA_AND(_temp1, _temp2), MBA_XOR(_temp3, _temp4)); v2 = (v2 << 3) | (v2 >> 61); break; \
            case 126: v3 = MBA_NOT(MBA_ADD(_temp1, _temp2)); v3 = MBA_OR(v3, MBA_AND(_temp3, _temp4)); break; \
            default: v4 = MBA_XOR(MBA_SUB(_temp1, _temp2), MBA_ADD(_temp3, _temp4)); v4 = MBA_NOT(v4); break; \
        } \
    } while (0)

#define POLYMORPHIC_HEAVY() \
    do { \
        JUNK_HEAVY; \
        volatile unsigned long long _chaos1 = __rdtsc(); \
        volatile unsigned long long _chaos2 = (unsigned long long)__readgsqword(0x60); \
        volatile unsigned long long _chaos3 = (unsigned long long)__readgsqword(0x30); \
        volatile unsigned long long _chaos4 = _chaos1 ^ _chaos2 ^ _chaos3; \
 \
        GRAPH_POLYMORPHIC_LAYER_1((_chaos1 ^ _chaos2), _chaos1, _chaos2, _chaos3, _chaos4); \
 \
        GRAPH_POLYMORPHIC_LAYER_1((_chaos2 ^ _chaos3), _chaos2, _chaos3, _chaos4, _chaos1); \
 \
        GRAPH_POLYMORPHIC_LAYER_1((_chaos3 ^ _chaos4), _chaos3, _chaos4, _chaos1, _chaos2); \
 \
        if (((_chaos1 | ~_chaos1) == ~0ULL) && (((_chaos2 & 0) == 0) || ((_chaos2 | 0) == _chaos2))) { \
 \
            for (volatile int _vmp_loop = 0; _vmp_loop < (((_chaos1 & 1) == 0) ? 0 : 1); _vmp_loop++) { \
                if (_chaos1 > _chaos2) { \
                    _chaos1 ^= _chaos2; \
                    _chaos1 = (_chaos1 << 13) | (_chaos1 >> 51); \
 \
                    if ((_chaos1 ^ (_chaos1 >> 32)) & 0x1000) { \
                        _chaos1 ^= _chaos3; \
 \
                        if (((_chaos1 * 2) >> 1) == _chaos1) { \
                            if (_chaos1 > 0x100000) { \
                                _chaos1 = ~_chaos1; \
 \
                                for (volatile int _k = 0; _k < (((_chaos1 & 0x200) == 0) ? 0 : 1); _k++) { \
                                    _chaos1 += __rdtsc(); \
                                } \
                            } else { \
                                _chaos1 += __rdtsc(); \
                            } \
                        } \
                    } else { \
                        _chaos1 = (_chaos1 << 7) | (_chaos1 >> 57); \
                    } \
                } else { \
                    _chaos2 ^= _chaos1; \
                    _chaos2 = (_chaos2 << 17) | (_chaos2 >> 47); \
                    if (_chaos2 & 0x2000) { \
                        _chaos2 = ~_chaos2; \
                        if (_chaos2 < 0x200000) { \
                            _chaos2 ^= __rdtsc(); \
                        } \
                    } \
                } \
            } \
 \
            if (((_chaos1 & _chaos2) ^ (_chaos1 & _chaos2)) != 0) { \
                _chaos1 = 0xDEADC0DE; \
                _chaos2 = 0xBADF00D; \
                _chaos3 = 0xFEEDFACE; \
            } \
        } \
        volatile unsigned long long _pdg = _chaos1 ^ _chaos2 ^ _chaos3 ^ _chaos4; \
        if (_pdg == 0) {  \
 \
        volatile int _vmp_state = (_chaos1 ^ _chaos2 ^ _chaos3) & 0x3F; \
        volatile int _vmp_done = 0; \
        while (!_vmp_done) { \
 \
            if (((_vmp_state ^ 0) == _vmp_state) && ((_vmp_state | 0) == _vmp_state)) { \
                switch (_vmp_state) { \
                    case 0: \
                        _chaos3 ^= 0xDEADBEEF; \
 \
                        for (volatile int _i = 0; _i < (((_chaos3 & 1) == 1) ? 1 : 0); _i++) { \
                            _chaos3 = (_chaos3 << 3) | (_chaos3 >> 61); \
                        } \
                        _vmp_done = 1; \
                        break; \
                    case 1: \
                        _chaos3 = ~_chaos3; \
                        if (((_chaos3 | ~_chaos3) == ~0ULL)) { _vmp_done = 1; } \
                        break; \
                    case 2: \
                        _chaos3 = (_chaos3 << 7) | (_chaos3 >> 57); \
 \
                        if ((_chaos3 ^ (_chaos3 >> 16)) & 0xFFFF) { \
                            _chaos3 ^= __rdtsc(); \
                        } \
                        _vmp_done = 1; \
                        break; \
                    case 3: \
                        _chaos3 += _chaos1; \
                        _vmp_done = 1; \
                        break; \
                    case 4: \
                        _chaos3 ^= _chaos2; \
                        if (((_chaos3 * 2) >> 1) == _chaos3) { _vmp_done = 1; } \
                        break; \
                    case 5: \
                        _chaos3 = (_chaos3 << 11) | (_chaos3 >> 53); \
                        _vmp_done = 1; \
                        break; \
                    case 6: \
                        _chaos3 -= _chaos1; \
 \
                        if (((_chaos3 & 0) == 0) || ((_chaos3 | ~_chaos3) == ~0ULL)) { \
                            _chaos3 = ~_chaos3; \
                        } \
                        _vmp_done = 1; \
                        break; \
                    case 7: \
                        _chaos3 ^= __rdtsc(); \
                        _vmp_done = 1; \
                        break; \
                    case 8: \
                        _chaos3 = (_chaos3 << 19) | (_chaos3 >> 45); \
                        _vmp_done = 1; \
                        break; \
                    case 9: \
                        _chaos3 += _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 10: \
                        _chaos3 = ~_chaos3 ^ _chaos1; \
                        _vmp_done = 1; \
                        break; \
                    case 11: \
                        _chaos3 = (_chaos3 << 23) | (_chaos3 >> 41); \
                        _vmp_done = 1; \
                        break; \
                    case 12: \
                        _chaos3 ^= 0xCAFEBABE; \
                        _vmp_done = 1; \
                        break; \
                    case 13: \
                        _chaos3 *= (_chaos1 | 1); \
                        _vmp_done = 1; \
                        break; \
                    case 14: \
                        _chaos3 = (_chaos3 << 29) | (_chaos3 >> 35); \
                        _vmp_done = 1; \
                        break; \
                    case 15: \
                        _chaos3 ^= (unsigned long long)__readgsqword(0x60); \
                        _vmp_done = 1; \
                        break; \
                    case 16: \
                        _chaos3 = (_chaos3 << 5) | (_chaos3 >> 59); \
                        _vmp_done = 1; \
                        break; \
                    case 17: \
                        _chaos3 += __rdtsc(); \
                        _vmp_done = 1; \
                        break; \
                    case 18: \
                        _chaos3 = ~_chaos3 + _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 19: \
                        _chaos3 = (_chaos3 << 15) | (_chaos3 >> 49); \
                        _vmp_done = 1; \
                        break; \
                    case 20: \
                        _chaos3 ^= 0xFEEDFACE; \
                        _vmp_done = 1; \
                        break; \
                    case 21: \
                        _chaos3 -= _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 22: \
                        _chaos3 = (_chaos3 << 27) | (_chaos3 >> 37); \
                        _vmp_done = 1; \
                        break; \
                    case 23: \
                        _chaos3 ^= (unsigned long long)__readgsqword(0x30); \
                        _vmp_done = 1; \
                        break; \
                    case 24: \
                        _chaos3 = ~_chaos3; \
                        _vmp_done = 1; \
                        break; \
                    case 25: \
                        _chaos3 = (_chaos3 << 9) | (_chaos3 >> 55); \
                        _vmp_done = 1; \
                        break; \
                    case 26: \
                        _chaos3 += _chaos1 + _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 27: \
                        _chaos3 = (_chaos3 << 21) | (_chaos3 >> 43); \
                        _vmp_done = 1; \
                        break; \
                    case 28: \
                        _chaos3 ^= __rdtsc() ^ _chaos1; \
                        _vmp_done = 1; \
                        break; \
                    case 29: \
                        _chaos3 = (_chaos3 << 31) | (_chaos3 >> 33); \
                        _vmp_done = 1; \
                        break; \
                    case 30: \
                        _chaos3 = ~_chaos3 ^ _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 31: \
                        _chaos3 ^= 0xDEADC0DE; \
                        _vmp_done = 1; \
                        break; \
                    case 32: \
                        _chaos3 = (_chaos3 << 13) | (_chaos3 >> 51); \
                        _vmp_done = 1; \
                        break; \
                    case 33: \
                        _chaos3 += _chaos1 ^ _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 34: \
                        _chaos3 = ~_chaos3 + __rdtsc(); \
                        _vmp_done = 1; \
                        break; \
                    case 35: \
                        _chaos3 = (_chaos3 << 17) | (_chaos3 >> 47); \
                        _vmp_done = 1; \
                        break; \
                    case 36: \
                        _chaos3 ^= 0xFEDCBA98; \
                        _vmp_done = 1; \
                        break; \
                    case 37: \
                        _chaos3 *= (_chaos2 | 1); \
                        _vmp_done = 1; \
                        break; \
                    case 38: \
                        _chaos3 = (_chaos3 << 25) | (_chaos3 >> 39); \
                        _vmp_done = 1; \
                        break; \
                    case 39: \
                        _chaos3 += (_chaos1 & _chaos2); \
                        _vmp_done = 1; \
                        break; \
                    case 40: \
                        _chaos3 = ~_chaos3 ^ __rdtsc(); \
                        _vmp_done = 1; \
                        break; \
                    case 41: \
                        _chaos3 = (_chaos3 << 11) | (_chaos3 >> 53); \
                        _vmp_done = 1; \
                        break; \
                    case 42: \
                        _chaos3 ^= (_chaos1 | _chaos2); \
                        _vmp_done = 1; \
                        break; \
                    case 43: \
                        _chaos3 = (_chaos3 << 19) | (_chaos3 >> 45); \
                        _vmp_done = 1; \
                        break; \
                    case 44: \
                        _chaos3 += 0xBADC0FFEE; \
                        _vmp_done = 1; \
                        break; \
                    case 45: \
                        _chaos3 = ~_chaos3 + _chaos1; \
                        _vmp_done = 1; \
                        break; \
                    case 46: \
                        _chaos3 = (_chaos3 << 23) | (_chaos3 >> 41); \
                        _vmp_done = 1; \
                        break; \
                    case 47: \
                        _chaos3 ^= (_chaos1 ^ _chaos2); \
                        _vmp_done = 1; \
                        break; \
                    case 48: \
                        _chaos3 = (_chaos3 << 7) | (_chaos3 >> 57); \
                        _vmp_done = 1; \
                        break; \
                    case 49: \
                        _chaos3 += __rdtsc() ^ _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 50: \
                        _chaos3 = ~_chaos3; \
                        _vmp_done = 1; \
                        break; \
                    case 51: \
                        _chaos3 = (_chaos3 << 29) | (_chaos3 >> 35); \
                        _vmp_done = 1; \
                        break; \
                    case 52: \
                        _chaos3 ^= 0x123456789ABCDEFULL; \
                        _vmp_done = 1; \
                        break; \
                    case 53: \
                        _chaos3 += (_chaos1 - _chaos2); \
                        _vmp_done = 1; \
                        break; \
                    case 54: \
                        _chaos3 = (_chaos3 << 15) | (_chaos3 >> 49); \
                        _vmp_done = 1; \
                        break; \
                    case 55: \
                        _chaos3 = ~_chaos3 ^ _chaos1 ^ _chaos2; \
                        _vmp_done = 1; \
                        break; \
                    case 56: \
                        _chaos3 = (_chaos3 << 21) | (_chaos3 >> 43); \
                        _vmp_done = 1; \
                        break; \
                    case 57: \
                        _chaos3 += (unsigned long long)__readgsqword(0x60); \
                        _vmp_done = 1; \
                        break; \
                    case 58: \
                        _chaos3 = ~_chaos3 + (_chaos1 | _chaos2); \
                        _vmp_done = 1; \
                        break; \
                    case 59: \
                        _chaos3 = (_chaos3 << 27) | (_chaos3 >> 37); \
                        _vmp_done = 1; \
                        break; \
                    case 60: \
                        _chaos3 ^= __rdtsc() + _chaos1; \
                        _vmp_done = 1; \
                        break; \
                    case 61: \
                        _chaos3 = (_chaos3 << 31) | (_chaos3 >> 33); \
                        _vmp_done = 1; \
                        break; \
                    case 62: \
                        _chaos3 += (_chaos1 * (_chaos2 | 1)); \
                        _vmp_done = 1; \
                        break; \
                    default: \
                        _chaos3 ^= 0xC0FFEE; \
                        _vmp_done = 1; \
                        break; \
                } \
            } \
        } \
        volatile unsigned long long _poly = _chaos1 ^ _chaos2 ^ _chaos3; \
 \
        if (((_poly | ~_poly) == ~0ULL) && (((_poly & 0xFF) < 0x40) || ((_poly & 0xFF) >= 0x40))) { \
            if ((_poly & 0xFF) < 0x40) { \
                _poly = ~_poly; \
 \
                for (volatile int _i = 0; _i < (((_poly & 0x1000) == 0) ? 0 : 1); _i++) { \
                    if (_poly & 0x1000) { \
                        _poly ^= __rdtsc(); \
                    } \
                } \
            } else if ((_poly & 0xFF) < 0x80) { \
                _poly = (_poly << 13) | (_poly >> 51); \
                if (((_poly * 2) >> 1) == _poly) { \
                    if (_poly & 0x2000) { \
                        _poly ^= (unsigned long long)__readgsqword(0x60); \
                    } \
                } \
            } else if ((_poly & 0xFF) < 0xC0) { \
                _poly = (_poly << 17) | (_poly >> 47); \
 \
                if ((_poly ^ (_poly >> 24)) & 0xFF) { \
                    if (_poly & 0x4000) { \
                        _poly = ~_poly + __rdtsc(); \
                    } \
                } \
            } else { \
                _poly ^= (unsigned long long)__readgsqword(0x30); \
                if (((_poly & 0) == 0) && (_poly & 0x8000)) { \
                    _poly = (_poly << 23) | (_poly >> 41); \
                } \
            } \
        } \
 \
        if (((_poly ^ _poly) != 0) || ((_poly & ~_poly) != 0)) { \
            _poly = 0xDEADC0DEBADF00DULL; \
        } \
 \
        volatile unsigned long long _layer1_a = _poly ^ __rdtsc(); \
        volatile unsigned long long _layer1_b = (unsigned long long)__readgsqword(0x60); \
        if (((_layer1_a | ~_layer1_a) == ~0ULL) && (((_layer1_b & 0) == 0) || ((_layer1_b | 0) == _layer1_b))) { \
            for (volatile int _l1_i = 0; _l1_i < (((_layer1_a & 1) == 1) ? 1 : 0); _l1_i++) { \
                if ((_layer1_a ^ (_layer1_a >> 32)) & 0xFFFF) { \
                    _layer1_a = (_layer1_a << 11) | (_layer1_a >> 53); \
                    if (((_layer1_a * 2) >> 1) == _layer1_a) { \
                        if (_layer1_a & 0x10000) { \
                            _layer1_a ^= _layer1_b; \
                            for (volatile int _l1_j = 0; _l1_j < (((_layer1_a & 0x200) == 0) ? 0 : 1); _l1_j++) { \
                                _layer1_a += __rdtsc(); \
                                if (_layer1_a & 0x400) { _layer1_a = ~_layer1_a; } \
                            } \
                        } else { \
                            _layer1_a = ~_layer1_a + _layer1_b; \
                        } \
                    } \
                } else { \
                    _layer1_a = (_layer1_a << 17) | (_layer1_a >> 47); \
                    if (_layer1_a & 0x20000) { \
                        _layer1_a ^= (unsigned long long)__readgsqword(0x30); \
                    } \
                } \
            } \
        } \
 \
        volatile int _layer2_state = (_layer1_a ^ _layer1_b ^ _poly) & 0x3F; \
        volatile int _layer2_done = 0; \
        while (!_layer2_done) { \
            if (((_layer2_state ^ 0) == _layer2_state) && ((_layer2_state | 0) == _layer2_state)) { \
                switch (_layer2_state) { \
                    case 0: _layer1_a ^= 0x11111111; _layer2_done = 1; break; \
                    case 1: _layer1_a = (_layer1_a << 3) | (_layer1_a >> 61); _layer2_done = 1; break; \
                    case 2: _layer1_a += _layer1_b; _layer2_done = 1; break; \
                    case 3: _layer1_a = ~_layer1_a; _layer2_done = 1; break; \
                    case 4: _layer1_a ^= __rdtsc(); _layer2_done = 1; break; \
                    case 5: _layer1_a = (_layer1_a << 7) | (_layer1_a >> 57); _layer2_done = 1; break; \
                    case 6: _layer1_a -= _layer1_b; _layer2_done = 1; break; \
                    case 7: _layer1_a ^= 0x22222222; _layer2_done = 1; break; \
                    case 8: _layer1_a = (_layer1_a << 13) | (_layer1_a >> 51); _layer2_done = 1; break; \
                    case 9: _layer1_a += __rdtsc(); _layer2_done = 1; break; \
                    case 10: _layer1_a = ~_layer1_a ^ _layer1_b; _layer2_done = 1; break; \
                    case 11: _layer1_a = (_layer1_a << 19) | (_layer1_a >> 45); _layer2_done = 1; break; \
                    case 12: _layer1_a ^= 0x33333333; _layer2_done = 1; break; \
                    case 13: _layer1_a *= (_layer1_b | 1); _layer2_done = 1; break; \
                    case 14: _layer1_a = (_layer1_a << 23) | (_layer1_a >> 41); _layer2_done = 1; break; \
                    case 15: _layer1_a += (_layer1_b ^ _poly); _layer2_done = 1; break; \
                    case 16: _layer1_a = (_layer1_a << 5) | (_layer1_a >> 59); _layer2_done = 1; break; \
                    case 17: _layer1_a ^= (unsigned long long)__readgsqword(0x60); _layer2_done = 1; break; \
                    case 18: _layer1_a = ~_layer1_a + _poly; _layer2_done = 1; break; \
                    case 19: _layer1_a = (_layer1_a << 29) | (_layer1_a >> 35); _layer2_done = 1; break; \
                    case 20: _layer1_a ^= 0x44444444; _layer2_done = 1; break; \
                    case 21: _layer1_a -= _poly; _layer2_done = 1; break; \
                    case 22: _layer1_a = (_layer1_a << 15) | (_layer1_a >> 49); _layer2_done = 1; break; \
                    case 23: _layer1_a += (unsigned long long)__readgsqword(0x30); _layer2_done = 1; break; \
                    case 24: _layer1_a = ~_layer1_a; _layer2_done = 1; break; \
                    case 25: _layer1_a = (_layer1_a << 9) | (_layer1_a >> 55); _layer2_done = 1; break; \
                    case 26: _layer1_a ^= (_layer1_b + _poly); _layer2_done = 1; break; \
                    case 27: _layer1_a = (_layer1_a << 21) | (_layer1_a >> 43); _layer2_done = 1; break; \
                    case 28: _layer1_a += __rdtsc() ^ _layer1_b; _layer2_done = 1; break; \
                    case 29: _layer1_a = (_layer1_a << 27) | (_layer1_a >> 37); _layer2_done = 1; break; \
                    case 30: _layer1_a ^= 0x55555555; _layer2_done = 1; break; \
                    case 31: _layer1_a = ~_layer1_a ^ _poly; _layer2_done = 1; break; \
                    case 32: _layer1_a = (_layer1_a << 11) | (_layer1_a >> 53); _layer2_done = 1; break; \
                    case 33: _layer1_a += (_layer1_b & _poly); _layer2_done = 1; break; \
                    case 34: _layer1_a = (_layer1_a << 17) | (_layer1_a >> 47); _layer2_done = 1; break; \
                    case 35: _layer1_a ^= 0x66666666; _layer2_done = 1; break; \
                    case 36: _layer1_a *= (_poly | 1); _layer2_done = 1; break; \
                    case 37: _layer1_a = (_layer1_a << 25) | (_layer1_a >> 39); _layer2_done = 1; break; \
                    case 38: _layer1_a += (_layer1_b | _poly); _layer2_done = 1; break; \
                    case 39: _layer1_a = ~_layer1_a + __rdtsc(); _layer2_done = 1; break; \
                    case 40: _layer1_a = (_layer1_a << 31) | (_layer1_a >> 33); _layer2_done = 1; break; \
                    case 41: _layer1_a ^= 0x77777777; _layer2_done = 1; break; \
                    case 42: _layer1_a -= (_layer1_b ^ _poly); _layer2_done = 1; break; \
                    case 43: _layer1_a = (_layer1_a << 13) | (_layer1_a >> 51); _layer2_done = 1; break; \
                    case 44: _layer1_a += (unsigned long long)__readgsqword(0x60); _layer2_done = 1; break; \
                    case 45: _layer1_a = ~_layer1_a ^ _layer1_b; _layer2_done = 1; break; \
                    case 46: _layer1_a = (_layer1_a << 19) | (_layer1_a >> 45); _layer2_done = 1; break; \
                    case 47: _layer1_a ^= 0x88888888; _layer2_done = 1; break; \
                    default: _layer1_a ^= 0x99999999; _layer2_done = 1; break; \
                } \
            } \
        } \
 \
        volatile unsigned long long _layer3_x = _layer1_a ^ _poly; \
        volatile unsigned long long _layer3_y = _layer1_b ^ __rdtsc(); \
        if (((_layer3_x | ~_layer3_x) == ~0ULL) && (((_layer3_y * 2) >> 1) == _layer3_y)) { \
            for (volatile int _l3_outer = 0; _l3_outer < (((_layer3_x & 1) == 1) ? 1 : 0); _l3_outer++) { \
                if ((_layer3_x ^ (_layer3_x >> 16)) & 0xFFFF) { \
                    _layer3_x = (_layer3_x << 7) | (_layer3_x >> 57); \
                    for (volatile int _l3_mid = 0; _l3_mid < (((_layer3_x & 0x100) == 0) ? 0 : 1); _l3_mid++) { \
                        if (_layer3_x & 0x200) { \
                            _layer3_x ^= _layer3_y; \
                            for (volatile int _l3_inner = 0; _l3_inner < (((_layer3_x & 0x400) == 0) ? 0 : 1); _l3_inner++) { \
                                _layer3_x += __rdtsc(); \
                                if (((_layer3_x & 0) == 0) && (_layer3_x & 0x800)) { \
                                    _layer3_x = ~_layer3_x; \
                                } \
                            } \
                        } else { \
                            _layer3_x = (_layer3_x << 13) | (_layer3_x >> 51); \
                        } \
                    } \
                } else { \
                    _layer3_x = ~_layer3_x + _layer3_y; \
                    if (_layer3_x & 0x1000) { \
                        _layer3_x ^= (unsigned long long)__readgsqword(0x30); \
                    } \
                } \
            } \
        } \
 \
        volatile int _layer4_state = (_layer3_x ^ _layer3_y) & 0x1F; \
        volatile int _layer4_done = 0; \
        while (!_layer4_done) { \
            if (((_layer4_state ^ 0) == _layer4_state) && ((_layer4_state | 0) == _layer4_state)) { \
                switch (_layer4_state) { \
                    case 0: _layer3_x ^= 0xAAAAAAAA; _layer4_done = 1; break; \
                    case 1: _layer3_x = (_layer3_x << 5) | (_layer3_x >> 59); _layer4_done = 1; break; \
                    case 2: _layer3_x += _layer3_y; _layer4_done = 1; break; \
                    case 3: _layer3_x = ~_layer3_x; _layer4_done = 1; break; \
                    case 4: _layer3_x ^= __rdtsc(); _layer4_done = 1; break; \
                    case 5: _layer3_x = (_layer3_x << 11) | (_layer3_x >> 53); _layer4_done = 1; break; \
                    case 6: _layer3_x -= _layer3_y; _layer4_done = 1; break; \
                    case 7: _layer3_x ^= 0xBBBBBBBB; _layer4_done = 1; break; \
                    case 8: _layer3_x = (_layer3_x << 17) | (_layer3_x >> 47); _layer4_done = 1; break; \
                    case 9: _layer3_x += __rdtsc(); _layer4_done = 1; break; \
                    case 10: _layer3_x = ~_layer3_x ^ _layer3_y; _layer4_done = 1; break; \
                    case 11: _layer3_x = (_layer3_x << 23) | (_layer3_x >> 41); _layer4_done = 1; break; \
                    case 12: _layer3_x ^= 0xCCCCCCCC; _layer4_done = 1; break; \
                    case 13: _layer3_x *= (_layer3_y | 1); _layer4_done = 1; break; \
                    case 14: _layer3_x = (_layer3_x << 29) | (_layer3_x >> 35); _layer4_done = 1; break; \
                    case 15: _layer3_x += (unsigned long long)__readgsqword(0x60); _layer4_done = 1; break; \
                    case 16: _layer3_x = (_layer3_x << 7) | (_layer3_x >> 57); _layer4_done = 1; break; \
                    case 17: _layer3_x ^= 0xDDDDDDDD; _layer4_done = 1; break; \
                    case 18: _layer3_x = ~_layer3_x + _layer3_y; _layer4_done = 1; break; \
                    case 19: _layer3_x = (_layer3_x << 13) | (_layer3_x >> 51); _layer4_done = 1; break; \
                    case 20: _layer3_x += (_layer3_y ^ _poly); _layer4_done = 1; break; \
                    case 21: _layer3_x = (_layer3_x << 19) | (_layer3_x >> 45); _layer4_done = 1; break; \
                    case 22: _layer3_x ^= 0xEEEEEEEE; _layer4_done = 1; break; \
                    case 23: _layer3_x -= _poly; _layer4_done = 1; break; \
                    case 24: _layer3_x = (_layer3_x << 25) | (_layer3_x >> 39); _layer4_done = 1; break; \
                    case 25: _layer3_x += (unsigned long long)__readgsqword(0x30); _layer4_done = 1; break; \
                    case 26: _layer3_x = ~_layer3_x; _layer4_done = 1; break; \
                    case 27: _layer3_x = (_layer3_x << 31) | (_layer3_x >> 33); _layer4_done = 1; break; \
                    case 28: _layer3_x ^= 0xFFFFFFFF; _layer4_done = 1; break; \
                    case 29: _layer3_x += __rdtsc() ^ _layer3_y; _layer4_done = 1; break; \
                    case 30: _layer3_x = (_layer3_x << 15) | (_layer3_x >> 49); _layer4_done = 1; break; \
                    default: _layer3_x ^= 0x12345678; _layer4_done = 1; break; \
                } \
            } \
        } \
 \
        volatile unsigned long long _layer5_p = _layer3_x ^ _layer1_a; \
        volatile unsigned long long _layer5_q = _layer3_y ^ _poly; \
        if (((_layer5_p | ~_layer5_p) == ~0ULL) && (((_layer5_q & 0) == 0) || ((_layer5_q | 0) == _layer5_q))) { \
            if ((_layer5_p & 0xFF) < 0x40) { \
                _layer5_p = (_layer5_p << 9) | (_layer5_p >> 55); \
                for (volatile int _l5_a = 0; _l5_a < (((_layer5_p & 1) == 1) ? 1 : 0); _l5_a++) { \
                    if (((_layer5_p * 2) >> 1) == _layer5_p) { \
                        _layer5_p ^= _layer5_q; \
                        if (_layer5_p & 0x2000) { \
                            _layer5_p = ~_layer5_p; \
                            for (volatile int _l5_b = 0; _l5_b < (((_layer5_p & 0x100) == 0) ? 0 : 1); _l5_b++) { \
                                _layer5_p += __rdtsc(); \
                            } \
                        } \
                    } \
                } \
            } else if ((_layer5_p & 0xFF) < 0x80) { \
                _layer5_p = (_layer5_p << 13) | (_layer5_p >> 51); \
                if ((_layer5_p ^ (_layer5_p >> 32)) & 0xFFFF) { \
                    _layer5_p ^= (unsigned long long)__readgsqword(0x60); \
                    if (_layer5_p & 0x4000) { \
                        _layer5_p = ~_layer5_p + _layer5_q; \
                    } \
                } \
            } else if ((_layer5_p & 0xFF) < 0xC0) { \
                _layer5_p = (_layer5_p << 17) | (_layer5_p >> 47); \
                for (volatile int _l5_c = 0; _l5_c < (((_layer5_p & 0x200) == 0) ? 0 : 1); _l5_c++) { \
                    if (_layer5_p & 0x8000) { \
                        _layer5_p ^= __rdtsc(); \
                    } \
                } \
            } else { \
                _layer5_p ^= (unsigned long long)__readgsqword(0x30); \
                if (((_layer5_p & 0) == 0) && (_layer5_p & 0x10000)) { \
                    _layer5_p = (_layer5_p << 23) | (_layer5_p >> 41); \
                } \
            } \
        } \
 \
        volatile int _layer6_state = (_layer5_p ^ _layer5_q ^ _layer3_x) & 0x3F; \
        volatile int _layer6_done = 0; \
        while (!_layer6_done) { \
            if (((_layer6_state ^ 0) == _layer6_state) && ((_layer6_state | 0) == _layer6_state)) { \
                switch (_layer6_state) { \
                    case 0: _layer5_p ^= 0x10101010; _layer6_done = 1; break; \
                    case 1: _layer5_p = (_layer5_p << 3) | (_layer5_p >> 61); _layer6_done = 1; break; \
                    case 2: _layer5_p += _layer5_q; _layer6_done = 1; break; \
                    case 3: _layer5_p = ~_layer5_p; _layer6_done = 1; break; \
                    case 4: _layer5_p ^= __rdtsc(); _layer6_done = 1; break; \
                    case 5: _layer5_p = (_layer5_p << 7) | (_layer5_p >> 57); _layer6_done = 1; break; \
                    case 6: _layer5_p -= _layer5_q; _layer6_done = 1; break; \
                    case 7: _layer5_p ^= 0x20202020; _layer6_done = 1; break; \
                    case 8: _layer5_p = (_layer5_p << 11) | (_layer5_p >> 53); _layer6_done = 1; break; \
                    case 9: _layer5_p += __rdtsc(); _layer6_done = 1; break; \
                    case 10: _layer5_p = ~_layer5_p ^ _layer5_q; _layer6_done = 1; break; \
                    case 11: _layer5_p = (_layer5_p << 13) | (_layer5_p >> 51); _layer6_done = 1; break; \
                    case 12: _layer5_p ^= 0x30303030; _layer6_done = 1; break; \
                    case 13: _layer5_p *= (_layer5_q | 1); _layer6_done = 1; break; \
                    case 14: _layer5_p = (_layer5_p << 17) | (_layer5_p >> 47); _layer6_done = 1; break; \
                    case 15: _layer5_p += (unsigned long long)__readgsqword(0x60); _layer6_done = 1; break; \
                    case 16: _layer5_p = (_layer5_p << 19) | (_layer5_p >> 45); _layer6_done = 1; break; \
                    case 17: _layer5_p ^= 0x40404040; _layer6_done = 1; break; \
                    case 18: _layer5_p = ~_layer5_p + _layer5_q; _layer6_done = 1; break; \
                    case 19: _layer5_p = (_layer5_p << 23) | (_layer5_p >> 41); _layer6_done = 1; break; \
                    case 20: _layer5_p += (_layer5_q ^ _layer3_x); _layer6_done = 1; break; \
                    case 21: _layer5_p = (_layer5_p << 29) | (_layer5_p >> 35); _layer6_done = 1; break; \
                    case 22: _layer5_p ^= 0x50505050; _layer6_done = 1; break; \
                    case 23: _layer5_p -= _layer3_x; _layer6_done = 1; break; \
                    case 24: _layer5_p = (_layer5_p << 31) | (_layer5_p >> 33); _layer6_done = 1; break; \
                    case 25: _layer5_p += (unsigned long long)__readgsqword(0x30); _layer6_done = 1; break; \
                    case 26: _layer5_p = ~_layer5_p; _layer6_done = 1; break; \
                    case 27: _layer5_p = (_layer5_p << 5) | (_layer5_p >> 59); _layer6_done = 1; break; \
                    case 28: _layer5_p ^= 0x60606060; _layer6_done = 1; break; \
                    case 29: _layer5_p += __rdtsc() ^ _layer5_q; _layer6_done = 1; break; \
                    case 30: _layer5_p = (_layer5_p << 9) | (_layer5_p >> 55); _layer6_done = 1; break; \
                    case 31: _layer5_p ^= 0x70707070; _layer6_done = 1; break; \
                    case 32: _layer5_p = (_layer5_p << 15) | (_layer5_p >> 49); _layer6_done = 1; break; \
                    case 33: _layer5_p += (_layer5_q & _layer3_x); _layer6_done = 1; break; \
                    case 34: _layer5_p = ~_layer5_p + __rdtsc(); _layer6_done = 1; break; \
                    case 35: _layer5_p = (_layer5_p << 21) | (_layer5_p >> 43); _layer6_done = 1; break; \
                    case 36: _layer5_p ^= 0x80808080; _layer6_done = 1; break; \
                    case 37: _layer5_p *= (_layer3_x | 1); _layer6_done = 1; break; \
                    case 38: _layer5_p = (_layer5_p << 25) | (_layer5_p >> 39); _layer6_done = 1; break; \
                    case 39: _layer5_p += (_layer5_q | _layer3_x); _layer6_done = 1; break; \
                    case 40: _layer5_p = ~_layer5_p ^ __rdtsc(); _layer6_done = 1; break; \
                    case 41: _layer5_p = (_layer5_p << 27) | (_layer5_p >> 37); _layer6_done = 1; break; \
                    case 42: _layer5_p ^= 0x90909090; _layer6_done = 1; break; \
                    case 43: _layer5_p -= (_layer5_q ^ _layer3_x); _layer6_done = 1; break; \
                    case 44: _layer5_p = (_layer5_p << 3) | (_layer5_p >> 61); _layer6_done = 1; break; \
                    case 45: _layer5_p += (unsigned long long)__readgsqword(0x60); _layer6_done = 1; break; \
                    case 46: _layer5_p = ~_layer5_p ^ _layer5_q; _layer6_done = 1; break; \
                    case 47: _layer5_p = (_layer5_p << 7) | (_layer5_p >> 57); _layer6_done = 1; break; \
                    case 48: _layer5_p ^= 0xA0A0A0A0; _layer6_done = 1; break; \
                    case 49: _layer5_p += (_layer5_q - _layer3_x); _layer6_done = 1; break; \
                    case 50: _layer5_p = (_layer5_p << 11) | (_layer5_p >> 53); _layer6_done = 1; break; \
                    case 51: _layer5_p = ~_layer5_p ^ _layer3_x; _layer6_done = 1; break; \
                    case 52: _layer5_p = (_layer5_p << 13) | (_layer5_p >> 51); _layer6_done = 1; break; \
                    case 53: _layer5_p ^= 0xB0B0B0B0; _layer6_done = 1; break; \
                    case 54: _layer5_p += __rdtsc() ^ _layer3_x; _layer6_done = 1; break; \
                    case 55: _layer5_p = (_layer5_p << 17) | (_layer5_p >> 47); _layer6_done = 1; break; \
                    case 56: _layer5_p ^= 0xC0C0C0C0; _layer6_done = 1; break; \
                    case 57: _layer5_p *= ((_layer5_q ^ _layer3_x) | 1); _layer6_done = 1; break; \
                    case 58: _layer5_p = (_layer5_p << 19) | (_layer5_p >> 45); _layer6_done = 1; break; \
                    case 59: _layer5_p = ~_layer5_p + (_layer5_q | _layer3_x); _layer6_done = 1; break; \
                    case 60: _layer5_p = (_layer5_p << 23) | (_layer5_p >> 41); _layer6_done = 1; break; \
                    case 61: _layer5_p ^= 0xD0D0D0D0; _layer6_done = 1; break; \
                    case 62: _layer5_p += (unsigned long long)__readgsqword(0x30); _layer6_done = 1; break; \
                    default: _layer5_p ^= 0xE0E0E0E0; _layer6_done = 1; break; \
                } \
            } \
        } \
    } } while (0)

#define BRKIDA do { \
        volatile unsigned long long _m = __rdtsc(); \
        volatile unsigned long long _n = (unsigned long long)__readgsqword(0x60); \
        volatile unsigned long long _p = (unsigned long long)__readgsqword(0x30); \
        volatile unsigned long long _q = _m ^ _n ^ _p; \
 \
        if (((_m ^ (_m ^ _m)) == _m) && ((_n | 0) == _n)) { \
            if ((_m & 0xFF) < 0x80) { \
                _m = (_m << 5) | (_m >> 59); \
                if (_m & 0x10) { _m ^= _p; } \
                if (_m & 0x20) { _m = ~_m; } \
                if (_m & 0x40) { _m += _q; } \
            } else { \
                _m = ~_m; \
                if (_m & 0x20) { _m += _p; } \
                if (_m & 0x80) { _m ^= _q; } \
                if (_m & 0x100) { _m = (_m << 7) | (_m >> 57); } \
            } \
        } \
 \
        volatile int _pre_state = (_m ^ _n) & 0xF; \
        for (volatile int _pre_loop = 0; _pre_loop < 1; _pre_loop++) { \
            switch (_pre_state) { \
                case 0: _m ^= 0xABCDEF; if (_m & 1) _m = ~_m; break; \
                case 1: _m = (_m << 3) | (_m >> 61); if (_m & 2) _m += _n; break; \
                case 2: _m += _n; if (_m & 4) _m ^= _p; break; \
                case 3: _m = ~_m; if (_m & 8) _m = (_m << 11) | (_m >> 53); break; \
                case 4: _m ^= _p; if (_m & 0x10) _m += _q; break; \
                case 5: _m = (_m << 9) | (_m >> 55); if (_m & 0x20) _m = ~_m; break; \
                case 6: _m -= _n; if (_m & 0x40) _m ^= _q; break; \
                case 7: _m ^= __rdtsc(); if (_m & 0x80) _m += _p; break; \
                case 8: _m = (_m << 13) | (_m >> 51); if (_m & 0x100) _m = ~_m; break; \
                case 9: _m += _q; if (_m & 0x200) _m ^= _n; break; \
                case 10: _m = ~_m; if (_m & 0x400) _m = (_m << 17) | (_m >> 47); break; \
                case 11: _m ^= _n; if (_m & 0x800) _m += _p; break; \
                case 12: _m = (_m << 19) | (_m >> 45); if (_m & 0x1000) _m ^= _q; break; \
                case 13: _m += _p; if (_m & 0x2000) _m = ~_m; break; \
                case 14: _m = ~_m; if (_m & 0x4000) _m ^= __rdtsc(); break; \
                default: _m ^= __rdtsc(); if (_m & 0x8000) _m = (_m << 23) | (_m >> 41); break; \
            } \
        } \
 \
        if (((_q | ~_q) == ~0ULL) && (((_m & 0xF) < 8) || ((_m & 0xF) >= 8))) { \
            volatile int _branch = (_m ^ _n ^ _p) & 0x1F; \
            if (_branch < 16) { \
                if (_branch & 1) { \
                    _m = (_m << 7) | (_m >> 57); \
                    if (_m & 0x10000) { _m ^= _n; } \
                    if (_m & 0x20000) { _m += _p; } \
                } else { \
                    _m = ~_m; \
                    if (_m & 0x40000) { _m ^= _q; } \
                    if (_m & 0x80000) { _m = (_m << 11) | (_m >> 53); } \
                } \
                if (_branch & 2) { \
                    _n = (_n << 13) | (_n >> 51); \
                    if (_n & 0x100000) { _n ^= _m; } \
                } else { \
                    _n = ~_n; \
                    if (_n & 0x200000) { _n += _p; } \
                } \
            } else { \
                if (_branch & 4) { \
                    _p = (_p << 17) | (_p >> 47); \
                    if (_p & 0x400000) { _p ^= _m; } \
                    if (_p & 0x800000) { _p += _n; } \
                } else { \
                    _p = ~_p; \
                    if (_p & 0x1000000) { _p ^= _q; } \
                    if (_p & 0x2000000) { _p = (_p << 19) | (_p >> 45); } \
                } \
                if (_branch & 8) { \
                    _q = (_q << 23) | (_q >> 41); \
                    if (_q & 0x4000000) { _q ^= _m; } \
                } else { \
                    _q = ~_q; \
                    if (_q & 0x8000000) { _q += _n; } \
                } \
            } \
        } \
 \
        if (((_m | ~_m) == ~0ULL) && (_m > _n)) { \
            if (_m & 0x1) { \
                _m ^= _n; \
                _m = (_m << 7) | (_m >> 57); \
 \
                for (volatile int _vmp_k = 0; _vmp_k < (((_m & 1) == 0) ? 0 : 1); _vmp_k++) { \
                    if (_m & 0x100) { \
                        if (_m & 0x200) { \
                            _m = ~_m; \
                            if (_m > 0x1000) { \
                                _m ^= __rdtsc(); \
                            } else { \
                                _m += _n; \
                            } \
                        } else { \
                            _m += _n; \
                            if (_m & 0x400) { \
                                _m = (_m << 11) | (_m >> 53); \
                            } \
                        } \
                    } else { \
                        if (_m & 0x800) { \
                            _m ^= 0xDEADBEEF; \
                        } else { \
                            _m = (_m << 13) | (_m >> 51); \
                        } \
                    } \
                } \
            } else { \
                _n ^= _m; \
                if (_n & 0x1000) { \
                    _n = (_n << 17) | (_n >> 47); \
                    if (_n & 0x2000) { \
                        _n = ~_n; \
                    } \
                } else { \
                    _n += __rdtsc(); \
                } \
            } \
        } else { \
 \
            if (((_n & 1) == 0) || ((_n & 1) == 1)) { \
                if (_n & 0x2) { \
                    _n ^= _m; \
                    _n = (_n << 13) | (_n >> 51); \
                    if (_n & 0x4000) { \
                        if (_n & 0x8000) { \
                            _n ^= __rdtsc(); \
                            if (_n > _m) { \
                                _n = ~_n; \
                            } \
                        } else { \
                            _n = (_n << 19) | (_n >> 45); \
                        } \
                    } else { \
                        _n += _m; \
                    } \
                } else { \
                    _m += _n; \
                    if (_m & 0x10000) { \
                        _m = (_m << 23) | (_m >> 41); \
                    } \
                } \
            } \
        } \
 \
        volatile int _state = (_m ^ _n) & 0xF; \
        volatile int _done = 0; \
        while (!_done) { \
            switch (_state) { \
                case 0: \
                    if (_m & 0x20000) { _m ^= 0xDEADBEEF; } else { _m = ~_m; } \
                    _done = 1; break; \
                case 1: \
                    if (_m > _n) { _m = ~_m; } else { _m += _n; } \
                    _done = 1; break; \
                case 2: \
                    _m = (_m << 11) | (_m >> 53); \
                    if (_m & 0x40000) { _m ^= __rdtsc(); } \
                    _done = 1; break; \
                case 3: \
                    if (_m & 0x80000) { _m += _n; } else { _m = (_m << 7) | (_m >> 57); } \
                    _done = 1; break; \
                case 4: \
                    _m ^= __rdtsc(); \
                    if (_m & 0x100000) { _m = ~_m; } \
                    _done = 1; break; \
                case 5: \
                    if (_m < _n) { _m = (_m << 19) | (_m >> 45); } else { _m ^= 0xCAFEBABE; } \
                    _done = 1; break; \
                case 6: \
                    _m -= _n; \
                    if (_m & 0x200000) { _m = ~_m; } \
                    _done = 1; break; \
                case 7: \
                    if (_m & 0x400000) { _m ^= (unsigned long long)__readgsqword(0x30); } else { _m = (_m << 13) | (_m >> 51); } \
                    _done = 1; break; \
                case 8: \
                    _m = (_m << 17) | (_m >> 47); \
                    if (_m > 0x800000) { _m ^= _n; } \
                    _done = 1; break; \
                case 9: \
                    if (_m & 0x1000000) { _m = ~_m + _n; } else { _m ^= __rdtsc(); } \
                    _done = 1; break; \
                case 10: \
                    _m += _n; \
                    if (_m & 0x2000000) { _m = (_m << 23) | (_m >> 41); } \
                    _done = 1; break; \
                case 11: \
                    if (_m > 0x4000000) { _m = (_m << 29) | (_m >> 35); } else { _m = ~_m; } \
                    _done = 1; break; \
                case 12: \
                    _m ^= 0xFEEDFACE; \
                    if (_m & 0x8000000) { _m += __rdtsc(); } \
                    _done = 1; break; \
                case 13: \
                    if (_m & 0x10000000) { _m *= (_n | 1); } else { _m = (_m << 5) | (_m >> 59); } \
                    _done = 1; break; \
                case 14: \
                    _m = (_m << 31) | (_m >> 33); \
                    if (_m < 0x20000000) { _m ^= _n; } \
                    _done = 1; break; \
                default: \
                    if (_m & 0x40000000) { _m ^= (unsigned long long)__readgsqword(0x30); } else { _m = ~_m; } \
                    _done = 1; break; \
            } \
        } \
 \
        volatile int _post_loop = ((_m & 0x3) == 0x3) ? 1 : ((_m & 0x3) == 0x2) ? 1 : ((_m & 0x3) == 0x1) ? 1 : 1; \
        for (volatile int _vmp_x = 0; _vmp_x < _post_loop; _vmp_x++) { \
            if (_m & 0x80000000ULL) { \
                _m = (_m << 7) | (_m >> 57); \
                if (_m > _n) { \
                    _m ^= _n; \
                    if (_m & 0x100000000ULL) { \
                        _m = (_m << 11) | (_m >> 53); \
                        if (_m & 0x200000000ULL) { _m ^= _p; } \
                    } else { \
                        _m += _q; \
                        if (_m & 0x400000000ULL) { _m = ~_m; } \
                    } \
                } else { \
                    _m += _n; \
                    if (_m & 0x800000000ULL) { \
                        _m = (_m << 13) | (_m >> 51); \
                        if (_m & 0x1000000000ULL) { _m ^= __rdtsc(); } \
                    } else { \
                        _m ^= _p; \
                        if (_m & 0x2000000000ULL) { _m = ~_m; } \
                    } \
                } \
            } else { \
                _m = ~_m; \
                if (_m < _n) { \
                    _m ^= __rdtsc(); \
                    if (_m & 0x4000000000ULL) { \
                        _m = (_m << 17) | (_m >> 47); \
                        if (_m & 0x8000000000ULL) { _m += _q; } \
                    } else { \
                        _m ^= _n; \
                        if (_m & 0x10000000000ULL) { _m = ~_m; } \
                    } \
                } else { \
                    _m += _p; \
                    if (_m & 0x20000000000ULL) { \
                        _m = (_m << 19) | (_m >> 45); \
                        if (_m & 0x40000000000ULL) { _m ^= _q; } \
                    } else { \
                        _m = ~_m; \
                        if (_m & 0x80000000000ULL) { _m += __rdtsc(); } \
                    } \
                } \
            } \
        } \
 \
        if (((_m ^ (_m >> 32)) & 0xFFFF) > 0x8000) { \
            _m = (_m << 13) | (_m >> 51); \
            if ((_m ^ (_m >> 16)) & 0xFF) { \
                _m ^= _n; \
                if (_m & 0x100000000000ULL) { \
                    _m = (_m << 23) | (_m >> 41); \
                    if (_m > _p) { _m += _q; } else { _m ^= _q; } \
                } else { \
                    _m = ~_m; \
                    if (_m < _p) { _m ^= __rdtsc(); } else { _m += _n; } \
                } \
            } else { \
                _m += _p; \
                if (_m & 0x200000000000ULL) { \
                    _m = (_m << 29) | (_m >> 35); \
                    if (_m & 0x400000000000ULL) { _m ^= _n; } \
                } else { \
                    _m = ~_m; \
                    if (_m & 0x800000000000ULL) { _m += _q; } \
                } \
            } \
        } else { \
            _m = (_m << 19) | (_m >> 45); \
            if ((_m ^ (_m >> 24)) & 0xFF) { \
                _m ^= _p; \
                if (_m & 0x1000000000000ULL) { \
                    _m = (_m << 31) | (_m >> 33); \
                    if (_m > _n) { _m ^= _q; } else { _m += _q; } \
                } else { \
                    _m = ~_m; \
                    if (_m < _n) { _m += __rdtsc(); } else { _m ^= _p; } \
                } \
            } else { \
                _m += _q; \
                if (_m & 0x2000000000000ULL) { \
                    _m = (_m << 5) | (_m >> 59); \
                    if (_m & 0x4000000000000ULL) { _m ^= _p; } \
                } else { \
                    _m = ~_m; \
                    if (_m & 0x8000000000000ULL) { _m += _n; } \
                } \
            } \
        } \
 \
        for (volatile int _final1 = 0; _final1 < (((_m & 0x4) == 0x4) ? 1 : 1); _final1++) { \
            if (_m & 0x10000000000000ULL) { \
                _m = (_m << 7) | (_m >> 57); \
                for (volatile int _final2 = 0; _final2 < (((_m & 0x8) == 0x8) ? 1 : 1); _final2++) { \
                    if (_m > _n) { \
                        _m ^= __rdtsc(); \
                        if (_m & 0x20000000000000ULL) { \
                            _m = (_m << 11) | (_m >> 53); \
                        } \
                    } else { \
                        _m += _p; \
                        if (_m & 0x40000000000000ULL) { \
                            _m = ~_m; \
                        } \
                    } \
                } \
            } else { \
                _m = ~_m; \
                if (_m & 0x80000000000000ULL) { \
                    _m ^= _q; \
                } \
            } \
        } \
    } while (0)

#define POLYMORPHIC_DISPATCH() \
    do { \
        volatile unsigned long long _chaos = __rdtsc(); \
        volatile unsigned long long _entropy = (unsigned long long)__readgsqword(0x60); \
        volatile unsigned long long _noise = (unsigned long long)__readgsqword(0x30); \
        volatile unsigned long long _vortex = _chaos ^ _entropy ^ _noise; \
 \
        if (((_chaos & _chaos) == _chaos) && ((_entropy | ~_entropy) == ~0ULL)) { \
            volatile int _pre_branch = (_chaos ^ _entropy) & 0x1F; \
            if (_pre_branch < 8) { \
                _chaos = (_chaos << 11) | (_chaos >> 53); \
                if (_chaos & 0x100) { \
                    _chaos ^= _noise; \
                    if (_chaos & 0x200) { _chaos = ~_chaos; } \
                    if (_chaos & 0x400) { _chaos += _vortex; } \
                } else { \
                    _chaos += _entropy; \
                    if (_chaos & 0x800) { _chaos ^= _vortex; } \
                    if (_chaos & 0x1000) { _chaos = (_chaos << 7) | (_chaos >> 57); } \
                } \
            } else if (_pre_branch < 16) { \
                _entropy = (_entropy << 17) | (_entropy >> 47); \
                if (_entropy & 0x200) { \
                    _entropy ^= _noise; \
                    if (_entropy & 0x2000) { _entropy = ~_entropy; } \
                    if (_entropy & 0x4000) { _entropy += _chaos; } \
                } else { \
                    _entropy += _vortex; \
                    if (_entropy & 0x8000) { _entropy ^= _chaos; } \
                    if (_entropy & 0x10000) { _entropy = (_entropy << 13) | (_entropy >> 51); } \
                } \
            } else if (_pre_branch < 24) { \
                _noise = (_noise << 19) | (_noise >> 45); \
                if (_noise & 0x20000) { \
                    _noise ^= _chaos; \
                    if (_noise & 0x40000) { _noise = ~_noise; } \
                    if (_noise & 0x80000) { _noise += _entropy; } \
                } else { \
                    _noise += _vortex; \
                    if (_noise & 0x100000) { _noise ^= _entropy; } \
                    if (_noise & 0x200000) { _noise = (_noise << 23) | (_noise >> 41); } \
                } \
            } else { \
                _vortex = (_vortex << 29) | (_vortex >> 35); \
                if (_vortex & 0x400000) { \
                    _vortex ^= _chaos; \
                    if (_vortex & 0x800000) { _vortex = ~_vortex; } \
                    if (_vortex & 0x1000000) { _vortex += _noise; } \
                } else { \
                    _vortex += _entropy; \
                    if (_vortex & 0x2000000) { _vortex ^= _noise; } \
                    if (_vortex & 0x4000000) { _vortex = (_vortex << 31) | (_vortex >> 33); } \
                } \
            } \
        } \
 \
        for (volatile int _vmp_pre = 0; _vmp_pre < (((_chaos & 1) == 1) ? 1 : ((_chaos & 1) == 0) ? 1 : 1); _vmp_pre++) { \
            if (_chaos & 0x400) { \
                _chaos = ~_chaos; \
                if (_chaos & 0x8000000) { \
                    _chaos = (_chaos << 5) | (_chaos >> 59); \
                    if (_chaos > _entropy) { _chaos ^= _noise; } else { _chaos += _vortex; } \
                } else { \
                    _chaos ^= _entropy; \
                    if (_chaos < _noise) { _chaos += __rdtsc(); } else { _chaos = ~_chaos; } \
                } \
            } else { \
                _chaos += _entropy; \
                if (_chaos & 0x10000000) { \
                    _chaos = (_chaos << 11) | (_chaos >> 53); \
                    if (_chaos & 0x20000000) { _chaos ^= _vortex; } else { _chaos += _noise; } \
                } else { \
                    _chaos = ~_chaos; \
                    if (_chaos & 0x40000000) { _chaos ^= __rdtsc(); } else { _chaos += _entropy; } \
                } \
            } \
        } \
 \
        if (((_chaos | 0) == _chaos) && (((_entropy & 0xFF) < 0x80) || ((_entropy & 0xFF) >= 0x80))) { \
            if ((_chaos & 0xFF) < 0x40) { \
                _chaos = (_chaos << 7) | (_chaos >> 57); \
                if (_chaos & 0x80000000ULL) { \
                    _chaos ^= _noise; \
                    if (_chaos > _entropy) { \
                        _chaos = (_chaos << 13) | (_chaos >> 51); \
                        if (_chaos & 0x100000000ULL) { _chaos += _vortex; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x200000000ULL) { _chaos ^= __rdtsc(); } \
                    } \
                } else { \
                    _chaos += _entropy; \
                    if (_chaos < _noise) { \
                        _chaos = (_chaos << 17) | (_chaos >> 47); \
                        if (_chaos & 0x400000000ULL) { _chaos ^= _vortex; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x800000000ULL) { _chaos += _noise; } \
                    } \
                } \
            } else if ((_chaos & 0xFF) < 0x80) { \
                _chaos = (_chaos << 19) | (_chaos >> 45); \
                if (_chaos & 0x1000000000ULL) { \
                    _chaos ^= _vortex; \
                    if (_chaos > _noise) { \
                        _chaos = (_chaos << 23) | (_chaos >> 41); \
                        if (_chaos & 0x2000000000ULL) { _chaos += _entropy; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x4000000000ULL) { _chaos ^= _noise; } \
                    } \
                } else { \
                    _chaos += _vortex; \
                    if (_chaos < _entropy) { \
                        _chaos = (_chaos << 29) | (_chaos >> 35); \
                        if (_chaos & 0x8000000000ULL) { _chaos ^= __rdtsc(); } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x10000000000ULL) { _chaos += _vortex; } \
                    } \
                } \
            } else if ((_chaos & 0xFF) < 0xC0) { \
                _chaos = (_chaos << 31) | (_chaos >> 33); \
                if (_chaos & 0x20000000000ULL) { \
                    _chaos ^= _entropy; \
                    if (_chaos > _vortex) { \
                        _chaos = (_chaos << 5) | (_chaos >> 59); \
                        if (_chaos & 0x40000000000ULL) { _chaos += _noise; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x80000000000ULL) { _chaos ^= _vortex; } \
                    } \
                } else { \
                    _chaos += _noise; \
                    if (_chaos < _vortex) { \
                        _chaos = (_chaos << 11) | (_chaos >> 53); \
                        if (_chaos & 0x100000000000ULL) { _chaos ^= _entropy; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x200000000000ULL) { _chaos += __rdtsc(); } \
                    } \
                } \
            } else { \
                _chaos = (_chaos << 15) | (_chaos >> 49); \
                if (_chaos & 0x400000000000ULL) { \
                    _chaos ^= _noise; \
                    if (_chaos > _entropy) { \
                        _chaos = (_chaos << 21) | (_chaos >> 43); \
                        if (_chaos & 0x800000000000ULL) { _chaos += _vortex; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x1000000000000ULL) { _chaos ^= _noise; } \
                    } \
                } else { \
                    _chaos += _entropy; \
                    if (_chaos < _noise) { \
                        _chaos = (_chaos << 27) | (_chaos >> 37); \
                        if (_chaos & 0x2000000000000ULL) { _chaos ^= _vortex; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x4000000000000ULL) { _chaos += __rdtsc(); } \
                    } \
                } \
            } \
        } \
        if (_chaos < _entropy) { \
            if (_chaos & 0x1) { \
                _chaos ^= _entropy; \
                _chaos = (_chaos << 13) | (_chaos >> 51); \
                if (_chaos & 0x400) { \
                    if (_chaos & 0x800) { \
                        _chaos = ~_chaos; \
                        if (_chaos > 0x100000) { \
                            _chaos ^= __rdtsc(); \
                        } else { \
                            _chaos += _entropy; \
                        } \
                    } else { \
                        _chaos = (_chaos << 7) | (_chaos >> 57); \
                    } \
                } else { \
                    if (_chaos & 0x1000) { \
                        _chaos ^= 0xDEADBEEF; \
                    } else { \
                        _chaos = (_chaos << 11) | (_chaos >> 53); \
                    } \
                } \
            } else { \
                _entropy ^= _chaos; \
                if (_entropy & 0x2000) { \
                    _entropy = (_entropy << 17) | (_entropy >> 47); \
                    if (_entropy & 0x4000) { \
                        _entropy = ~_entropy; \
                    } \
                } else { \
                    _entropy += __rdtsc(); \
                } \
            } \
        } else { \
            if (_entropy & 0x2) { \
                _entropy ^= _chaos; \
                _entropy = (_entropy << 17) | (_entropy >> 47); \
                if (_entropy & 0x8000) { \
                    if (_entropy & 0x10000) { \
                        _entropy ^= __rdtsc(); \
                        if (_entropy > _chaos) { \
                            _entropy = ~_entropy; \
                        } \
                    } else { \
                        _entropy = (_entropy << 19) | (_entropy >> 45); \
                    } \
                } else { \
                    _entropy += _chaos; \
                } \
            } else { \
                _chaos += _entropy; \
                if (_chaos & 0x20000) { \
                    _chaos = (_chaos << 23) | (_chaos >> 41); \
                } \
            } \
        } \
        switch ((_chaos ^ _entropy) & 0x1F) { \
            case 0: \
                if (_chaos & 0x40000) { \
                    _chaos ^= 0xCAFEBABE; \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 1: \
                if (_chaos > _entropy) { \
                    _chaos = ~_chaos; \
                } else { \
                    _chaos += _entropy; \
                } \
                break; \
            case 2: \
                _chaos = (_chaos << 7) | (_chaos >> 57); \
                if (_chaos & 0x80000) { \
                    _chaos ^= __rdtsc(); \
                } \
                break; \
            case 3: \
                if (_chaos & 0x100000) { \
                    _chaos += _entropy; \
                } else { \
                    _chaos = (_chaos << 11) | (_chaos >> 53); \
                } \
                break; \
            case 4: \
                _chaos ^= __rdtsc(); \
                if (_chaos & 0x200000) { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 5: \
                if (_chaos < _entropy) { \
                    _chaos = (_chaos << 23) | (_chaos >> 41); \
                } else { \
                    _chaos ^= 0xFEEDFACE; \
                } \
                break; \
            case 6: \
                _chaos -= _entropy; \
                if (_chaos & 0x400000) { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 7: \
                if (_chaos & 0x800000) { \
                    _chaos ^= (unsigned long long)__readgsqword(0x30); \
                } else { \
                    _chaos = (_chaos << 13) | (_chaos >> 51); \
                } \
                break; \
            case 8: \
                _chaos = (_chaos << 17) | (_chaos >> 47); \
                if (_chaos > 0x1000000) { \
                    _chaos ^= _entropy; \
                } \
                break; \
            case 9: \
                if (_chaos & 0x2000000) { \
                    _chaos = ~_chaos + _entropy; \
                } else { \
                    _chaos ^= __rdtsc(); \
                } \
                break; \
            case 10: \
                _chaos += _entropy; \
                if (_chaos & 0x4000000) { \
                    _chaos = (_chaos << 19) | (_chaos >> 45); \
                } \
                break; \
            case 11: \
                if (_chaos > 0x8000000) { \
                    _chaos = (_chaos << 29) | (_chaos >> 35); \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 12: \
                _chaos ^= 0xDEADC0DE; \
                if (_chaos & 0x10000000) { \
                    _chaos += __rdtsc(); \
                } \
                break; \
            case 13: \
                if (_chaos & 0x20000000) { \
                    _chaos *= (_entropy | 1); \
                } else { \
                    _chaos = (_chaos << 5) | (_chaos >> 59); \
                } \
                break; \
            case 14: \
                _chaos = (_chaos << 31) | (_chaos >> 33); \
                if (_chaos < 0x40000000) { \
                    _chaos ^= _entropy; \
                } \
                break; \
            case 15: \
                if (_chaos & 0x80000000ULL) { \
                    _chaos ^= (unsigned long long)__readgsqword(0x60); \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 16: \
                _chaos = (_chaos << 9) | (_chaos >> 55); \
                if (_chaos & 0x100000000ULL) { \
                    _chaos += _entropy; \
                } \
                break; \
            case 17: \
                if (_chaos > 0x200000000ULL) { \
                    _chaos += __rdtsc(); \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 18: \
                _chaos = ~_chaos + _entropy; \
                if (_chaos & 0x400000000ULL) { \
                    _chaos ^= 0xCAFEBABE; \
                } \
                break; \
            case 19: \
                if (_chaos & 0x800000000ULL) { \
                    _chaos = (_chaos << 15) | (_chaos >> 49); \
                } else { \
                    _chaos += __rdtsc(); \
                } \
                break; \
            case 20: \
                _chaos ^= 0xFEDCBA98; \
                if (_chaos > _entropy) { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 21: \
                if (_chaos & 0x1000000000ULL) { \
                    _chaos -= _entropy; \
                } else { \
                    _chaos = (_chaos << 21) | (_chaos >> 43); \
                } \
                break; \
            case 22: \
                _chaos = (_chaos << 27) | (_chaos >> 37); \
                if (_chaos & 0x2000000000ULL) { \
                    _chaos ^= _entropy; \
                } \
                break; \
            case 23: \
                if (_chaos < 0x4000000000ULL) { \
                    _chaos ^= (unsigned long long)__readgsqword(0x30); \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 24: \
                _chaos = ~_chaos; \
                if (_chaos & 0x8000000000ULL) { \
                    _chaos += __rdtsc(); \
                } \
                break; \
            case 25: \
                if (_chaos & 0x10000000000ULL) { \
                    _chaos = (_chaos << 9) | (_chaos >> 55); \
                } else { \
                    _chaos ^= 0xDEADBEEF; \
                } \
                break; \
            case 26: \
                _chaos += _entropy; \
                if (_chaos > 0x20000000000ULL) { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 27: \
                if (_chaos & 0x40000000000ULL) { \
                    _chaos = (_chaos << 21) | (_chaos >> 43); \
                } else { \
                    _chaos += __rdtsc(); \
                } \
                break; \
            case 28: \
                _chaos ^= __rdtsc() ^ _entropy; \
                if (_chaos & 0x80000000000ULL) { \
                    _chaos = ~_chaos; \
                } \
                break; \
            case 29: \
                if (_chaos > 0x100000000000ULL) { \
                    _chaos = (_chaos << 31) | (_chaos >> 33); \
                } else { \
                    _chaos ^= 0xCAFEBABE; \
                } \
                break; \
            case 30: \
                _chaos = ~_chaos ^ _entropy; \
                if (_chaos & 0x200000000000ULL) { \
                    _chaos += __rdtsc(); \
                } \
                break; \
            default: \
                if (_chaos & 0x400000000000ULL) { \
                    _chaos ^= 0xDEADC0DE; \
                } else { \
                    _chaos = ~_chaos; \
                } \
                break; \
        } \
 \
        if (((_chaos ^ 0) == _chaos) || ((_entropy & ~_entropy) == 0)) { \
            volatile int _post_state = (_chaos ^ _entropy ^ _noise ^ _vortex) & 0x1F; \
            for (volatile int _post_iter = 0; _post_iter < 1; _post_iter++) { \
                switch (_post_state) { \
                    case 0: \
                        _chaos ^= 0x12345678; \
                        if (_chaos & 0x800000000000ULL) { _chaos = ~_chaos; if (_chaos & 1) _chaos += _entropy; } \
                        break; \
                    case 1: \
                        _chaos = (_chaos << 7) | (_chaos >> 57); \
                        if (_chaos > _entropy) { _chaos += _noise; if (_chaos & 2) _chaos ^= _vortex; } \
                        break; \
                    case 2: \
                        _chaos += _entropy; \
                        if (_chaos & 0x1000000000000ULL) { _chaos ^= __rdtsc(); if (_chaos & 4) _chaos = ~_chaos; } \
                        break; \
                    case 3: \
                        _chaos = ~_chaos; \
                        if (_chaos < _noise) { _chaos = (_chaos << 13) | (_chaos >> 51); if (_chaos & 8) _chaos += _vortex; } \
                        break; \
                    case 4: \
                        _chaos ^= _noise; \
                        if ((_chaos ^ (_chaos >> 16)) & 0xFFFF) { _chaos += _entropy; if (_chaos & 0x10) _chaos = ~_chaos; } \
                        break; \
                    case 5: \
                        _chaos = (_chaos << 19) | (_chaos >> 45); \
                        if (_chaos & 0x2000000000000ULL) { _chaos = ~_chaos; if (_chaos & 0x20) _chaos ^= _noise; } \
                        break; \
                    case 6: \
                        _chaos -= _entropy; \
                        if (_chaos > 0x4000000000000ULL) { _chaos ^= _noise; if (_chaos & 0x40) _chaos += _vortex; } \
                        break; \
                    case 7: \
                        _chaos ^= __rdtsc(); \
                        if (_chaos & 0x8000000000000ULL) { _chaos = (_chaos << 23) | (_chaos >> 41); if (_chaos & 0x80) _chaos = ~_chaos; } \
                        break; \
                    case 8: \
                        _chaos = (_chaos << 11) | (_chaos >> 53); \
                        if (_chaos & 0x10000000000000ULL) { _chaos ^= _vortex; if (_chaos & 0x100) _chaos += _entropy; } \
                        break; \
                    case 9: \
                        _chaos += _vortex; \
                        if (_chaos > _noise) { _chaos = ~_chaos; if (_chaos & 0x200) _chaos ^= __rdtsc(); } \
                        break; \
                    case 10: \
                        _chaos = ~_chaos; \
                        if (_chaos < _entropy) { _chaos = (_chaos << 17) | (_chaos >> 47); if (_chaos & 0x400) _chaos += _noise; } \
                        break; \
                    case 11: \
                        _chaos ^= _entropy; \
                        if (_chaos & 0x20000000000000ULL) { _chaos += _vortex; if (_chaos & 0x800) _chaos = ~_chaos; } \
                        break; \
                    case 12: \
                        _chaos = (_chaos << 29) | (_chaos >> 35); \
                        if (_chaos > _vortex) { _chaos ^= _noise; if (_chaos & 0x1000) _chaos += __rdtsc(); } \
                        break; \
                    case 13: \
                        _chaos += _noise; \
                        if (_chaos & 0x40000000000000ULL) { _chaos = ~_chaos; if (_chaos & 0x2000) _chaos ^= _entropy; } \
                        break; \
                    case 14: \
                        _chaos = (_chaos << 31) | (_chaos >> 33); \
                        if (_chaos < _vortex) { _chaos ^= _entropy; if (_chaos & 0x4000) _chaos += _noise; } \
                        break; \
                    case 15: \
                        _chaos ^= _vortex; \
                        if (_chaos & 0x80000000000000ULL) { _chaos = (_chaos << 5) | (_chaos >> 59); if (_chaos & 0x8000) _chaos = ~_chaos; } \
                        break; \
                    case 16: \
                        _chaos = (_chaos << 15) | (_chaos >> 49); \
                        if (_chaos > _entropy) { _chaos += _noise; if (_chaos & 0x10000) _chaos ^= _vortex; } \
                        break; \
                    case 17: \
                        _chaos += __rdtsc(); \
                        if (_chaos & 0x100000000000000ULL) { _chaos = ~_chaos; if (_chaos & 0x20000) _chaos ^= _entropy; } \
                        break; \
                    case 18: \
                        _chaos = ~_chaos; \
                        if (_chaos < _noise) { _chaos = (_chaos << 21) | (_chaos >> 43); if (_chaos & 0x40000) _chaos += _vortex; } \
                        break; \
                    case 19: \
                        _chaos ^= _noise; \
                        if (_chaos > _vortex) { _chaos += _entropy; if (_chaos & 0x80000) _chaos = ~_chaos; } \
                        break; \
                    case 20: \
                        _chaos = (_chaos << 27) | (_chaos >> 37); \
                        if (_chaos & 0x200000000000000ULL) { _chaos ^= _vortex; if (_chaos & 0x100000) _chaos += __rdtsc(); } \
                        break; \
                    case 21: \
                        _chaos += _entropy; \
                        if (_chaos < _vortex) { _chaos = ~_chaos; if (_chaos & 0x200000) _chaos ^= _noise; } \
                        break; \
                    case 22: \
                        _chaos = (_chaos << 9) | (_chaos >> 55); \
                        if (_chaos & 0x400000000000000ULL) { _chaos ^= _entropy; if (_chaos & 0x400000) _chaos += _vortex; } \
                        break; \
                    case 23: \
                        _chaos ^= _vortex; \
                        if (_chaos > _noise) { _chaos = (_chaos << 13) | (_chaos >> 51); if (_chaos & 0x800000) _chaos = ~_chaos; } \
                        break; \
                    case 24: \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x800000000000000ULL) { _chaos += _noise; if (_chaos & 0x1000000) _chaos ^= __rdtsc(); } \
                        break; \
                    case 25: \
                        _chaos = (_chaos << 25) | (_chaos >> 39); \
                        if (_chaos < _entropy) { _chaos ^= _vortex; if (_chaos & 0x2000000) _chaos += _noise; } \
                        break; \
                    case 26: \
                        _chaos += _vortex; \
                        if (_chaos > _entropy) { _chaos = ~_chaos; if (_chaos & 0x4000000) _chaos ^= _noise; } \
                        break; \
                    case 27: \
                        _chaos = (_chaos << 3) | (_chaos >> 61); \
                        if (_chaos & 0x1000000000000000ULL) { _chaos ^= _noise; if (_chaos & 0x8000000) _chaos += _entropy; } \
                        break; \
                    case 28: \
                        _chaos ^= __rdtsc(); \
                        if (_chaos < _vortex) { _chaos = (_chaos << 19) | (_chaos >> 45); if (_chaos & 0x10000000) _chaos = ~_chaos; } \
                        break; \
                    case 29: \
                        _chaos = ~_chaos; \
                        if (_chaos > _noise) { _chaos += _vortex; if (_chaos & 0x20000000) _chaos ^= _entropy; } \
                        break; \
                    case 30: \
                        _chaos = (_chaos << 11) | (_chaos >> 53); \
                        if (_chaos & 0x2000000000000000ULL) { _chaos ^= _entropy; if (_chaos & 0x40000000) _chaos += __rdtsc(); } \
                        break; \
                    default: \
                        _chaos ^= __rdtsc(); \
                        if (_chaos & 0x4000000000000000ULL) { _chaos = (_chaos << 23) | (_chaos >> 41); if (_chaos & 0x80000000ULL) _chaos = ~_chaos; } \
                        break; \
                } \
            } \
        } \
 \
        volatile int _final_loop = ((_chaos & 0x2) == 0x2) ? 1 : ((_chaos & 0x2) == 0) ? 1 : 1; \
        for (volatile int _vmp_final = 0; _vmp_final < _final_loop; _vmp_final++) { \
            if (_chaos & 0x10000000000000ULL) { \
                _chaos = (_chaos << 29) | (_chaos >> 35); \
                if (_chaos > _entropy) { \
                    _chaos ^= _noise; \
                    if (_chaos & 0x8000000000000000ULL) { \
                        _chaos = (_chaos << 7) | (_chaos >> 57); \
                        if (_chaos > _vortex) { _chaos += _entropy; } else { _chaos ^= _vortex; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos < _noise) { _chaos += __rdtsc(); } else { _chaos ^= _entropy; } \
                    } \
                } else { \
                    _chaos += _vortex; \
                    if (_chaos & 0x100000000ULL) { \
                        _chaos = (_chaos << 13) | (_chaos >> 51); \
                        if (_chaos & 0x200000000ULL) { _chaos ^= _noise; } else { _chaos += _entropy; } \
                    } else { \
                        _chaos = ~_chaos; \
                        if (_chaos & 0x400000000ULL) { _chaos ^= _vortex; } else { _chaos += __rdtsc(); } \
                    } \
                } \
            } else { \
                _chaos ^= _entropy ^ _noise; \
                if (_chaos < _vortex) { \
                    _chaos = (_chaos << 17) | (_chaos >> 47); \
                    if (_chaos & 0x800000000ULL) { \
                        _chaos ^= __rdtsc(); \
                        if (_chaos > _noise) { _chaos += _vortex; } else { _chaos = ~_chaos; } \
                    } else { \
                        _chaos += _entropy; \
                        if (_chaos < _noise) { _chaos ^= _vortex; } else { _chaos = ~_chaos; } \
                    } \
                } else { \
                    _chaos = ~_chaos; \
                    if (_chaos & 0x1000000000ULL) { \
                        _chaos = (_chaos << 23) | (_chaos >> 41); \
                        if (_chaos & 0x2000000000ULL) { _chaos ^= _entropy; } else { _chaos += _noise; } \
                    } else { \
                        _chaos ^= _vortex; \
                        if (_chaos & 0x4000000000ULL) { _chaos += __rdtsc(); } else { _chaos = ~_chaos; } \
                    } \
                } \
            } \
        } \
    } while (0)

// tied everything together with this macro, just sprinkle this in critical parts of your code
#define MEGA_888888888888X(...) \
    do { \
        BRKIDA_EXTREME; \
        POLYMORPHIC_HEAVY(); \
    } while (0)

#else

#define BRKIDA do { \
    volatile int _x = 0; \
    for(int _i=0;_i<50;++_i) { \
        _x += _i; \
        _x ^= (_i << 3); \
        _x = ~_x; \
    } \
} while(0)

#define BRKIDA_EXTREME do { \
    volatile unsigned long long _bx1 = __rdtsc(); \
    volatile unsigned long long _bx2 = (unsigned long long)__readgsqword(0x60); \
    volatile unsigned long long _bx3 = _bx1 ^ _bx2; \
 \
    if (((_bx1 & 0x1) | ((_bx1 & 0x1) ^ 0x1)) != 0) { \
        if (((_bx2 & 0x2) | ((_bx2 & 0x2) ^ 0x2)) != 0) { \
            if (((_bx3 & 0x4) | ((_bx3 & 0x4) ^ 0x4)) != 0) { \
                if (((_bx1 > _bx2) | (_bx1 <= _bx2)) != 0) { \
                    if (((_bx3 < _bx1) | (_bx3 >= _bx1)) != 0) { \
                        if ((((_bx1 ^ _bx2) & 0x8) | (((_bx1 ^ _bx2) & 0x8) ^ 0x8)) != 0) { \
                            if ((((_bx2 + _bx3) & 0x10) | (((_bx2 + _bx3) & 0x10) ^ 0x10)) != 0) { \
                                if ((((_bx1 * 3) & 0x20) | (((_bx1 * 3) & 0x20) ^ 0x20)) != 0) { \
                                    if ((((_bx2 << 1) & 0x40) | (((_bx2 << 1) & 0x40) ^ 0x40)) != 0) { \
                                        if ((((_bx3 >> 2) & 0x80) | (((_bx3 >> 2) & 0x80) ^ 0x80)) != 0) { \
                                            if ((((_bx1 + _bx3) & 0x100) | (((_bx1 + _bx3) & 0x100) ^ 0x100)) != 0) { \
                                                if ((((_bx2 ^ _bx1) & 0x200) | (((_bx2 ^ _bx1) & 0x200) ^ 0x200)) != 0) { \
                                                    if ((((_bx3 * 5) & 0x400) | (((_bx3 * 5) & 0x400) ^ 0x400)) != 0) { \
                                                        if ((((_bx1 << 3) & 0x800) | (((_bx1 << 3) & 0x800) ^ 0x800)) != 0) { \
                                                            if ((((_bx2 >> 4) & 0x1000) | (((_bx2 >> 4) & 0x1000) ^ 0x1000)) != 0) { \
                                                                if ((((_bx3 + _bx2) & 0x2000) | (((_bx3 + _bx2) & 0x2000) ^ 0x2000)) != 0) { \
                                                                    if ((((_bx1 ^ _bx3) & 0x4000) | (((_bx1 ^ _bx3) & 0x4000) ^ 0x4000)) != 0) { \
                                                                        if ((((_bx2 * 7) & 0x8000) | (((_bx2 * 7) & 0x8000) ^ 0x8000)) != 0) { \
                                                                            if ((((_bx3 << 5) & 0x10000) | (((_bx3 << 5) & 0x10000) ^ 0x10000)) != 0) { \
                                                                                if ((((_bx1 >> 6) & 0x20000) | (((_bx1 >> 6) & 0x20000) ^ 0x20000)) != 0) { \
                                                                                    if ((((_bx2 + _bx1) & 0x40000) | (((_bx2 + _bx1) & 0x40000) ^ 0x40000)) != 0) { \
                                                                                        if ((((_bx3 ^ _bx2) & 0x80000) | (((_bx3 ^ _bx2) & 0x80000) ^ 0x80000)) != 0) { \
                                                                                            if ((((_bx1 * 11) & 0x100000) | (((_bx1 * 11) & 0x100000) ^ 0x100000)) != 0) { \
                                                                                                if ((((_bx2 << 7) & 0x200000) | (((_bx2 << 7) & 0x200000) ^ 0x200000)) != 0) { \
                                                                                                    if ((((_bx3 >> 8) & 0x400000) | (((_bx3 >> 8) & 0x400000) ^ 0x400000)) != 0) { \
                                                                                                        _bx1 = (_bx1 << 13) | (_bx1 >> 51); \
                                                                                                        _bx2 = ~_bx2; \
                                                                                                        _bx3 ^= 0xDEADBEEFCAFEBABE; \
                                                                                                    } \
                                                                                                } \
                                                                                            } \
                                                                                        } \
                                                                                    } \
                                                                                } \
                                                                            } \
                                                                        } \
                                                                    } \
                                                                } \
                                                            } \
                                                        } \
                                                    } \
                                                } \
                                            } \
                                        } \
                                    } \
                                } \
                            } \
                        } \
                    } \
                } \
            } \
        } \
    } \
 \
    volatile int _state = (_bx1 ^ _bx2 ^ _bx3) & 0x7F; \
    for (volatile int _iter = 0; _iter < 1; ++_iter) { \
        switch (_state % 100) { \
            case 0: _bx1 ^= 0xFEDCBA98; break; \
            case 1: _bx2 = (_bx2 << 5) | (_bx2 >> 59); break; \
            case 2: _bx3 += _bx1; break; \
            case 3: _bx1 = ~_bx1; break; \
            case 4: _bx2 ^= __rdtsc(); break; \
            case 5: _bx3 = (_bx3 << 11) | (_bx3 >> 53); break; \
            case 6: _bx1 += _bx2; break; \
            case 7: _bx2 = ~_bx2; break; \
            case 8: _bx3 ^= 0xCAFEBABE; break; \
            case 9: _bx1 = (_bx1 << 17) | (_bx1 >> 47); break; \
            case 10: _bx2 += _bx3; break; \
            case 11: _bx3 = ~_bx3; break; \
            case 12: _bx1 ^= __rdtsc(); break; \
            case 13: _bx2 = (_bx2 << 23) | (_bx2 >> 41); break; \
            case 14: _bx3 += _bx2; break; \
            case 15: _bx1 = ~_bx1; break; \
            case 16: _bx2 ^= 0xDEADC0DE; break; \
            case 17: _bx3 = (_bx3 << 31) | (_bx3 >> 33); break; \
            case 18: _bx1 += _bx3; break; \
            case 19: _bx2 = ~_bx2; break; \
            case 20: _bx3 ^= __rdtsc(); break; \
            case 21: _bx1 = (_bx1 << 9) | (_bx1 >> 55); break; \
            case 22: _bx2 += _bx1; break; \
            case 23: _bx3 = ~_bx3; break; \
            case 24: _bx1 ^= 0xFEEDFACE; break; \
            case 25: _bx2 = (_bx2 << 21) | (_bx2 >> 43); break; \
            case 26: _bx3 += _bx2; break; \
            case 27: _bx1 = ~_bx1; break; \
            case 28: _bx2 ^= __rdtsc(); break; \
            case 29: _bx3 = (_bx3 << 25) | (_bx3 >> 39); break; \
            case 30: _bx1 += _bx3; break; \
            case 31: _bx2 = ~_bx2; break; \
            case 32: _bx3 ^= 0xBAADF00D; break; \
            case 33: _bx1 = (_bx1 << 7) | (_bx1 >> 57); break; \
            case 34: _bx2 += _bx3; break; \
            case 35: _bx3 = ~_bx3; break; \
            case 36: _bx1 ^= __rdtsc(); break; \
            case 37: _bx2 = (_bx2 << 13) | (_bx2 >> 51); break; \
            case 38: _bx3 += _bx1; break; \
            case 39: _bx1 = ~_bx1; break; \
            case 40: _bx2 ^= 0xC0FFEE00; break; \
            case 41: _bx3 = (_bx3 << 19) | (_bx3 >> 45); break; \
            case 42: _bx1 += _bx2; break; \
            case 43: _bx2 = ~_bx2; break; \
            case 44: _bx3 ^= __rdtsc(); break; \
            case 45: _bx1 = (_bx1 << 29) | (_bx1 >> 35); break; \
            case 46: _bx2 += _bx3; break; \
            case 47: _bx3 = ~_bx3; break; \
            case 48: _bx1 ^= 0x8BADF00D; break; \
            case 49: _bx2 = (_bx2 << 3) | (_bx2 >> 61); break; \
            default: _bx3 += _bx1; _bx1 ^= _bx2; _bx2 = ~_bx2; break; \
        } \
    } \
} while(0)

#define POLYMORPHIC_DISPATCH() do { \
    volatile unsigned long long _pd1 = __rdtsc(); \
    volatile unsigned long long _pd2 = (unsigned long long)__readgsqword(0x30); \
    volatile unsigned long long _pd3 = _pd1 ^ _pd2; \
 \
    if (((_pd1 & 0x1) | ((_pd1 & 0x1) ^ 0x1)) != 0) { \
        if (((_pd2 & 0x2) | ((_pd2 & 0x2) ^ 0x2)) != 0) { \
            if (((_pd3 & 0x4) | ((_pd3 & 0x4) ^ 0x4)) != 0) { \
                if (((_pd1 > _pd2) | (_pd1 <= _pd2)) != 0) { \
                    if (((_pd3 < _pd1) | (_pd3 >= _pd1)) != 0) { \
                        if ((((_pd1 ^ _pd2) & 0x8) | (((_pd1 ^ _pd2) & 0x8) ^ 0x8)) != 0) { \
                            if ((((_pd2 + _pd3) & 0x10) | (((_pd2 + _pd3) & 0x10) ^ 0x10)) != 0) { \
                                if ((((_pd1 * 3) & 0x20) | (((_pd1 * 3) & 0x20) ^ 0x20)) != 0) { \
                                    if ((((_pd2 << 1) & 0x40) | (((_pd2 << 1) & 0x40) ^ 0x40)) != 0) { \
                                        if ((((_pd3 >> 2) & 0x80) | (((_pd3 >> 2) & 0x80) ^ 0x80)) != 0) { \
                                            if ((((_pd1 + _pd3) & 0x100) | (((_pd1 + _pd3) & 0x100) ^ 0x100)) != 0) { \
                                                if ((((_pd2 ^ _pd1) & 0x200) | (((_pd2 ^ _pd1) & 0x200) ^ 0x200)) != 0) { \
                                                    if ((((_pd3 * 5) & 0x400) | (((_pd3 * 5) & 0x400) ^ 0x400)) != 0) { \
                                                        if ((((_pd1 << 3) & 0x800) | (((_pd1 << 3) & 0x800) ^ 0x800)) != 0) { \
                                                            if ((((_pd2 >> 4) & 0x1000) | (((_pd2 >> 4) & 0x1000) ^ 0x1000)) != 0) { \
                                                                if ((((_pd3 + _pd2) & 0x2000) | (((_pd3 + _pd2) & 0x2000) ^ 0x2000)) != 0) { \
                                                                    if ((((_pd1 ^ _pd3) & 0x4000) | (((_pd1 ^ _pd3) & 0x4000) ^ 0x4000)) != 0) { \
                                                                        if ((((_pd2 * 7) & 0x8000) | (((_pd2 * 7) & 0x8000) ^ 0x8000)) != 0) { \
                                                                            if ((((_pd3 << 5) & 0x10000) | (((_pd3 << 5) & 0x10000) ^ 0x10000)) != 0) { \
                                                                                if ((((_pd1 >> 6) & 0x20000) | (((_pd1 >> 6) & 0x20000) ^ 0x20000)) != 0) { \
                                                                                    _pd1 = (_pd1 << 11) | (_pd1 >> 53); \
                                                                                    _pd2 = ~_pd2; \
                                                                                    _pd3 ^= 0xDEADBEEF; \
                                                                                } \
                                                                            } \
                                                                        } \
                                                                    } \
                                                                } \
                                                            } \
                                                        } \
                                                    } \
                                                } \
                                            } \
                                        } \
                                    } \
                                } \
                            } \
                        } \
                    } \
                } \
            } \
        } \
    } \
 \
    volatile int _pd_state = (_pd1 ^ _pd2 ^ _pd3) & 0x3F; \
    for (volatile int _pd_iter = 0; _pd_iter < 1; ++_pd_iter) { \
        switch (_pd_state % 50) { \
            case 0: _pd1 ^= 0xFEDCBA98; break; \
            case 1: _pd2 = (_pd2 << 5) | (_pd2 >> 59); break; \
            case 2: _pd3 += _pd1; break; \
            case 3: _pd1 = ~_pd1; break; \
            case 4: _pd2 ^= __rdtsc(); break; \
            case 5: _pd3 = (_pd3 << 11) | (_pd3 >> 53); break; \
            case 6: _pd1 += _pd2; break; \
            case 7: _pd2 = ~_pd2; break; \
            case 8: _pd3 ^= 0xCAFEBABE; break; \
            case 9: _pd1 = (_pd1 << 17) | (_pd1 >> 47); break; \
            case 10: _pd2 += _pd3; break; \
            case 11: _pd3 = ~_pd3; break; \
            case 12: _pd1 ^= __rdtsc(); break; \
            case 13: _pd2 = (_pd2 << 23) | (_pd2 >> 41); break; \
            case 14: _pd3 += _pd2; break; \
            case 15: _pd1 = ~_pd1; break; \
            case 16: _pd2 ^= 0xDEADC0DE; break; \
            case 17: _pd3 = (_pd3 << 31) | (_pd3 >> 33); break; \
            case 18: _pd1 += _pd3; break; \
            case 19: _pd2 = ~_pd2; break; \
            case 20: _pd3 ^= __rdtsc(); break; \
            case 21: _pd1 = (_pd1 << 9) | (_pd1 >> 55); break; \
            case 22: _pd2 += _pd1; break; \
            case 23: _pd3 = ~_pd3; break; \
            case 24: _pd1 ^= 0xFEEDFACE; break; \
            default: _pd2 = ~_pd2; _pd3 ^= _pd1; break; \
        } \
    } \
} while(0)

#define POLYMORPHIC_HEAVY() do { \
    volatile unsigned long long _ph1 = __rdtsc(); \
    volatile unsigned long long _ph2 = (unsigned long long)__readgsqword(0x60); \
    volatile unsigned long long _ph3 = _ph1 ^ _ph2; \
 \
    for (volatile int _i = 0; _i < 1; ++_i) { \
        if (_ph1 & 0x1) { \
            if (_ph2 & 0x2) { \
                if (_ph3 & 0x4) { \
                    if (_ph1 > _ph2) { \
                        if (_ph3 < _ph1) { \
                            if ((_ph1 ^ _ph2) & 0x8) { \
                                if ((_ph2 + _ph3) & 0x10) { \
                                    if ((_ph1 * 3) & 0x20) { \
                                        if ((_ph2 << 1) & 0x40) { \
                                            if ((_ph3 >> 2) & 0x80) { \
                                                _ph1 = (_ph1 << 7) | (_ph1 >> 57); \
                                                _ph2 = ~_ph2; \
                                                _ph3 ^= 0xDEADBEEF; \
                                            } else { \
                                                _ph1 ^= _ph3; \
                                                _ph2 = (_ph2 << 11) | (_ph2 >> 53); \
                                            } \
                                        } else { \
                                            _ph2 += _ph1; \
                                            _ph3 = (_ph3 << 13) | (_ph3 >> 51); \
                                        } \
                                    } else { \
                                        _ph1 = ~_ph1; \
                                        _ph3 ^= _ph2; \
                                    } \
                                } else { \
                                    _ph2 ^= __rdtsc(); \
                                    _ph1 += _ph3; \
                                } \
                            } else { \
                                _ph3 = (_ph3 << 17) | (_ph3 >> 47); \
                                _ph2 = ~_ph2; \
                            } \
                        } else { \
                            _ph1 ^= _ph2; \
                            _ph3 += __rdtsc(); \
                        } \
                    } else { \
                        _ph2 = (_ph2 << 19) | (_ph2 >> 45); \
                        _ph1 ^= _ph3; \
                    } \
                } else { \
                    _ph3 = ~_ph3; \
                    _ph1 += _ph2; \
                } \
            } else { \
                _ph2 ^= _ph1; \
                _ph3 = (_ph3 << 23) | (_ph3 >> 41); \
            } \
        } else { \
            _ph1 = (_ph1 << 29) | (_ph1 >> 35); \
            _ph2 ^= _ph3; \
        } \
    } \
 \
    volatile int _state = (_ph1 ^ _ph2 ^ _ph3) & 0x1F; \
    volatile int _done = 0; \
    while (!_done) { \
        switch (_state) { \
            case 0: _ph1 ^= 0xFEDCBA98; if (_ph1 & 0x100) _ph1 = ~_ph1; _done = 1; break; \
            case 1: _ph2 = (_ph2 << 5) | (_ph2 >> 59); if (_ph2 > _ph1) _ph2 ^= _ph3; _done = 1; break; \
            case 2: _ph3 += _ph1; if (_ph3 & 0x200) _ph3 = (_ph3 << 7) | (_ph3 >> 57); _done = 1; break; \
            case 3: _ph1 = ~_ph1; if (_ph1 < _ph2) _ph1 += _ph3; _done = 1; break; \
            case 4: _ph2 ^= __rdtsc(); if (_ph2 & 0x400) _ph2 = ~_ph2; _done = 1; break; \
            case 5: _ph3 = (_ph3 << 11) | (_ph3 >> 53); if (_ph3 > _ph2) _ph3 ^= _ph1; _done = 1; break; \
            case 6: _ph1 += _ph2; if (_ph1 & 0x800) _ph1 = (_ph1 << 13) | (_ph1 >> 51); _done = 1; break; \
            case 7: _ph2 = ~_ph2; if (_ph2 < _ph3) _ph2 += _ph1; _done = 1; break; \
            case 8: _ph3 ^= 0xCAFEBABE; if (_ph3 & 0x1000) _ph3 = ~_ph3; _done = 1; break; \
            case 9: _ph1 = (_ph1 << 17) | (_ph1 >> 47); if (_ph1 > _ph3) _ph1 ^= _ph2; _done = 1; break; \
            case 10: _ph2 += _ph3; if (_ph2 & 0x2000) _ph2 = (_ph2 << 19) | (_ph2 >> 45); _done = 1; break; \
            case 11: _ph3 = ~_ph3; if (_ph3 < _ph1) _ph3 += _ph2; _done = 1; break; \
            case 12: _ph1 ^= __rdtsc(); if (_ph1 & 0x4000) _ph1 = ~_ph1; _done = 1; break; \
            case 13: _ph2 = (_ph2 << 23) | (_ph2 >> 41); if (_ph2 > _ph1) _ph2 ^= _ph3; _done = 1; break; \
            case 14: _ph3 += _ph2; if (_ph3 & 0x8000) _ph3 = (_ph3 << 29) | (_ph3 >> 35); _done = 1; break; \
            case 15: _ph1 = ~_ph1; if (_ph1 < _ph3) _ph1 += _ph2; _done = 1; break; \
            case 16: _ph2 ^= 0xDEADC0DE; if (_ph2 & 0x10000) _ph2 = ~_ph2; _done = 1; break; \
            case 17: _ph3 = (_ph3 << 31) | (_ph3 >> 33); if (_ph3 > _ph2) _ph3 ^= _ph1; _done = 1; break; \
            case 18: _ph1 += _ph3; if (_ph1 & 0x20000) _ph1 = (_ph1 << 3) | (_ph1 >> 61); _done = 1; break; \
            case 19: _ph2 = ~_ph2; if (_ph2 < _ph1) _ph2 += _ph3; _done = 1; break; \
            case 20: _ph3 ^= __rdtsc(); if (_ph3 & 0x40000) _ph3 = ~_ph3; _done = 1; break; \
            case 21: _ph1 = (_ph1 << 9) | (_ph1 >> 55); if (_ph1 > _ph3) _ph1 ^= _ph2; _done = 1; break; \
            case 22: _ph2 += _ph1; if (_ph2 & 0x80000) _ph2 = (_ph2 << 15) | (_ph2 >> 49); _done = 1; break; \
            case 23: _ph3 = ~_ph3; if (_ph3 < _ph2) _ph3 += _ph1; _done = 1; break; \
            case 24: _ph1 ^= 0xFEEDFACE; if (_ph1 & 0x100000) _ph1 = ~_ph1; _done = 1; break; \
            case 25: _ph2 = (_ph2 << 21) | (_ph2 >> 43); if (_ph2 > _ph1) _ph2 ^= _ph3; _done = 1; break; \
            case 26: _ph3 += _ph2; if (_ph3 & 0x200000) _ph3 = (_ph3 << 27) | (_ph3 >> 37); _done = 1; break; \
            case 27: _ph1 = ~_ph1; if (_ph1 < _ph3) _ph1 += _ph2; _done = 1; break; \
            case 28: _ph2 ^= __rdtsc(); if (_ph2 & 0x400000) _ph2 = ~_ph2; _done = 1; break; \
            case 29: _ph3 = (_ph3 << 25) | (_ph3 >> 39); if (_ph3 > _ph2) _ph3 ^= _ph1; _done = 1; break; \
            case 30: _ph1 += _ph3; if (_ph1 & 0x800000) _ph1 = (_ph1 << 33) | (_ph1 >> 31); _done = 1; break; \
            default: _ph2 = ~_ph2; _ph3 ^= _ph1; _done = 1; break; \
        } \
    } \
 \
    for (volatile int _l1 = 0; _l1 < (((_ph1 & 0x1) == 0x1) ? 1 : 1); ++_l1) { \
        if (_ph1 & 0x1000000) { \
            for (volatile int _l2 = 0; _l2 < (((_ph2 & 0x2) == 0x2) ? 1 : 1); ++_l2) { \
                if (_ph2 & 0x2000000) { \
                    for (volatile int _l3 = 0; _l3 < (((_ph3 & 0x4) == 0x4) ? 1 : 1); ++_l3) { \
                        if (_ph3 & 0x4000000) { \
                            for (volatile int _l4 = 0; _l4 < (((_ph1 & 0x8) == 0x8) ? 1 : 1); ++_l4) { \
                                if (_ph1 & 0x8000000) { \
                                    for (volatile int _l5 = 0; _l5 < (((_ph2 & 0x10) == 0x10) ? 1 : 1); ++_l5) { \
                                        _ph1 ^= _ph2; \
                                        _ph2 = (_ph2 << 7) | (_ph2 >> 57); \
                                        _ph3 = ~_ph3; \
                                    } \
                                } else { \
                                    _ph1 += _ph3; \
                                } \
                            } \
                        } else { \
                            _ph2 ^= _ph1; \
                        } \
                    } \
                } else { \
                    _ph3 += _ph2; \
                } \
            } \
        } else { \
            _ph1 ^= __rdtsc(); \
        } \
    } \
} while(0)

#define JUNK_HEAVY do { \
    volatile int _z = 0; \
    for(int _i=0;_i<200;++_i) { \
        _z += _i; \
        _z ^= (_i << 7); \
        _z = ~_z; \
        _z = (_z << 11) | (_z >> 21); \
    } \
} while(0)

#define VM_OP_NOP 0x00
#define VM_OP_LOAD 0x01
#define VM_OP_STORE 0x02
#define VM_OP_ADD 0x03
#define VM_OP_SUB 0x04
#define VM_OP_XOR 0x05
#define VM_OP_OR 0x06
#define VM_OP_AND 0x07
#define VM_OP_NOT 0x08
#define VM_OP_ROL 0x09
#define VM_OP_ROR 0x0A
#define VM_OP_MUL 0x0B
#define VM_OP_DIV 0x0C
#define VM_OP_MOD 0x0D
#define VM_OP_SHL 0x0E
#define VM_OP_SHR 0x0F
#define VM_OP_JMP 0x10
#define VM_OP_JZ 0x11
#define VM_OP_JNZ 0x12
#define VM_OP_JG 0x13
#define VM_OP_JL 0x14
#define VM_OP_CALL 0x15
#define VM_OP_RET 0x16
#define VM_OP_PUSH 0x17
#define VM_OP_POP 0x18
#define VM_OP_CMP 0x19
#define VM_OP_TEST 0x1A
#define VM_OP_RDTSC 0x1B
#define VM_OP_GSREAD 0x1C
#define VM_OP_MBA_XOR 0x1D
#define VM_OP_MBA_AND 0x1E
#define VM_OP_MBA_OR 0x1F

#define VM_CONTEXT_INIT(ctx, seed) \
    do { \
        (ctx).r0 = (seed); \
        (ctx).r1 = __rdtsc(); \
        (ctx).r2 = (unsigned long long)__readgsqword(0x60); \
        (ctx).r3 = (unsigned long long)__readgsqword(0x30); \
        (ctx).r4 = (ctx).r0 ^ (ctx).r1; \
        (ctx).r5 = (ctx).r2 ^ (ctx).r3; \
        (ctx).r6 = (ctx).r4 ^ (ctx).r5; \
        (ctx).r7 = (ctx).r0 + (ctx).r1 + (ctx).r2 + (ctx).r3; \
        (ctx).pc = 0; \
        (ctx).flags = 0; \
    } while (0)

#define VM_EXECUTE_GRAPH(ctx, iterations) \
    do { \
        for (volatile int _vm_iter = 0; _vm_iter < (iterations); ++_vm_iter) { \
            volatile int _opcode = ((ctx).r0 ^ (ctx).r1 ^ (ctx).r2 ^ (ctx).r3 ^ (ctx).pc) & 0xFF; \
            switch (_opcode) { \
                case 0: (ctx).r0 = MBA_XOR((ctx).r0, (ctx).r1); (ctx).pc++; break; \
                case 1: (ctx).r1 = MBA_ADD((ctx).r1, (ctx).r2); (ctx).pc++; break; \
                case 2: (ctx).r2 = MBA_SUB((ctx).r2, (ctx).r3); (ctx).pc++; break; \
                case 3: (ctx).r3 = MBA_OR((ctx).r3, (ctx).r4); (ctx).pc++; break; \
                case 4: (ctx).r4 = MBA_AND((ctx).r4, (ctx).r5); (ctx).pc++; break; \
                case 5: (ctx).r5 = MBA_NOT((ctx).r5); (ctx).pc++; break; \
                case 6: (ctx).r6 = ((ctx).r6 << 7) | ((ctx).r6 >> 57); (ctx).pc++; break; \
                case 7: (ctx).r7 = ((ctx).r7 << 11) | ((ctx).r7 >> 53); (ctx).pc++; break; \
                case 8: (ctx).r0 ^= (ctx).r7; (ctx).pc++; break; \
                case 9: (ctx).r1 += (ctx).r6; (ctx).pc++; break; \
                case 10: (ctx).r2 -= (ctx).r5; (ctx).pc++; break; \
                case 11: (ctx).r3 |= (ctx).r4; (ctx).pc++; break; \
                case 12: (ctx).r4 &= (ctx).r3; (ctx).pc++; break; \
                case 13: (ctx).r5 = ~(ctx).r2; (ctx).pc++; break; \
                case 14: (ctx).r6 = ((ctx).r6 << 13) | ((ctx).r6 >> 51); (ctx).pc++; break; \
                case 15: (ctx).r7 = ((ctx).r7 << 17) | ((ctx).r7 >> 47); (ctx).pc++; break; \
                case 16: (ctx).r0 = MBA_XOR((ctx).r0, (ctx).r2); (ctx).pc++; break; \
                case 17: (ctx).r1 = MBA_ADD((ctx).r1, (ctx).r3); (ctx).pc++; break; \
                case 18: (ctx).r2 = MBA_SUB((ctx).r2, (ctx).r4); (ctx).pc++; break; \
                case 19: (ctx).r3 = MBA_OR((ctx).r3, (ctx).r5); (ctx).pc++; break; \
                case 20: (ctx).r4 = MBA_AND((ctx).r4, (ctx).r6); (ctx).pc++; break; \
                case 21: (ctx).r5 = MBA_NOT((ctx).r7); (ctx).pc++; break; \
                case 22: (ctx).r6 = ((ctx).r6 << 19) | ((ctx).r6 >> 45); (ctx).pc++; break; \
                case 23: (ctx).r7 = ((ctx).r7 << 23) | ((ctx).r7 >> 41); (ctx).pc++; break; \
                case 24: (ctx).r0 ^= (ctx).r3; (ctx).pc++; break; \
                case 25: (ctx).r1 += (ctx).r4; (ctx).pc++; break; \
                case 26: (ctx).r2 -= (ctx).r5; (ctx).pc++; break; \
                case 27: (ctx).r3 |= (ctx).r6; (ctx).pc++; break; \
                case 28: (ctx).r4 &= (ctx).r7; (ctx).pc++; break; \
                case 29: (ctx).r5 = ~(ctx).r0; (ctx).pc++; break; \
                case 30: (ctx).r6 = ((ctx).r6 << 29) | ((ctx).r6 >> 35); (ctx).pc++; break; \
                case 31: (ctx).r7 = ((ctx).r7 << 31) | ((ctx).r7 >> 33); (ctx).pc++; break; \
                case 32: (ctx).r0 = MBA_XOR((ctx).r0, (ctx).r4); (ctx).pc++; break; \
                case 33: (ctx).r1 = MBA_ADD((ctx).r1, (ctx).r5); (ctx).pc++; break; \
                case 34: (ctx).r2 = MBA_SUB((ctx).r2, (ctx).r6); (ctx).pc++; break; \
                case 35: (ctx).r3 = MBA_OR((ctx).r3, (ctx).r7); (ctx).pc++; break; \
                case 36: (ctx).r4 = MBA_AND((ctx).r4, (ctx).r0); (ctx).pc++; break; \
                case 37: (ctx).r5 = MBA_NOT((ctx).r1); (ctx).pc++; break; \
                case 38: (ctx).r6 = ((ctx).r6 << 5) | ((ctx).r6 >> 59); (ctx).pc++; break; \
                case 39: (ctx).r7 = ((ctx).r7 << 9) | ((ctx).r7 >> 55); (ctx).pc++; break; \
                case 40: (ctx).r0 ^= (ctx).r5; (ctx).pc++; break; \
                case 41: (ctx).r1 += (ctx).r6; (ctx).pc++; break; \
                case 42: (ctx).r2 -= (ctx).r7; (ctx).pc++; break; \
                case 43: (ctx).r3 |= (ctx).r0; (ctx).pc++; break; \
                case 44: (ctx).r4 &= (ctx).r1; (ctx).pc++; break; \
                case 45: (ctx).r5 = ~(ctx).r2; (ctx).pc++; break; \
                case 46: (ctx).r6 = ((ctx).r6 << 15) | ((ctx).r6 >> 49); (ctx).pc++; break; \
                case 47: (ctx).r7 = ((ctx).r7 << 21) | ((ctx).r7 >> 43); (ctx).pc++; break; \
                case 48: (ctx).r0 = MBA_XOR((ctx).r0, (ctx).r6); (ctx).pc++; break; \
                case 49: (ctx).r1 = MBA_ADD((ctx).r1, (ctx).r7); (ctx).pc++; break; \
                case 50: (ctx).r2 = MBA_SUB((ctx).r2, (ctx).r0); (ctx).pc++; break; \
                case 51: (ctx).r3 = MBA_OR((ctx).r3, (ctx).r1); (ctx).pc++; break; \
                case 52: (ctx).r4 = MBA_AND((ctx).r4, (ctx).r2); (ctx).pc++; break; \
                case 53: (ctx).r5 = MBA_NOT((ctx).r3); (ctx).pc++; break; \
                case 54: (ctx).r6 = ((ctx).r6 << 25) | ((ctx).r6 >> 39); (ctx).pc++; break; \
                case 55: (ctx).r7 = ((ctx).r7 << 27) | ((ctx).r7 >> 37); (ctx).pc++; break; \
                case 56: (ctx).r0 ^= (ctx).r7; (ctx).pc++; break; \
                case 57: (ctx).r1 += (ctx).r0; (ctx).pc++; break; \
                case 58: (ctx).r2 -= (ctx).r1; (ctx).pc++; break; \
                case 59: (ctx).r3 |= (ctx).r2; (ctx).pc++; break; \
                case 60: (ctx).r4 &= (ctx).r3; (ctx).pc++; break; \
                case 61: (ctx).r5 = ~(ctx).r4; (ctx).pc++; break; \
                case 62: (ctx).r6 = ((ctx).r6 << 3) | ((ctx).r6 >> 61); (ctx).pc++; break; \
                case 63: (ctx).r7 = ((ctx).r7 << 7) | ((ctx).r7 >> 57); (ctx).pc++; break; \
                case 64: (ctx).r0 = MBA_XOR(MBA_ADD((ctx).r0, (ctx).r1), MBA_OR((ctx).r2, (ctx).r3)); (ctx).pc++; break; \
                case 65: (ctx).r1 = MBA_AND(MBA_SUB((ctx).r1, (ctx).r2), MBA_XOR((ctx).r3, (ctx).r4)); (ctx).pc++; break; \
                case 66: (ctx).r2 = MBA_OR(MBA_NOT((ctx).r2), MBA_AND((ctx).r3, (ctx).r4)); (ctx).pc++; break; \
                case 67: (ctx).r3 = MBA_ADD(MBA_XOR((ctx).r3, (ctx).r4), MBA_SUB((ctx).r5, (ctx).r6)); (ctx).pc++; break; \
                case 68: (ctx).r4 = MBA_SUB(MBA_OR((ctx).r4, (ctx).r5), MBA_AND((ctx).r6, (ctx).r7)); (ctx).pc++; break; \
                case 69: (ctx).r5 = MBA_XOR(MBA_NOT((ctx).r5), MBA_ADD((ctx).r6, (ctx).r7)); (ctx).pc++; break; \
                case 70: (ctx).r6 = MBA_AND(MBA_XOR((ctx).r6, (ctx).r7), MBA_OR((ctx).r0, (ctx).r1)); (ctx).pc++; break; \
                case 71: (ctx).r7 = MBA_OR(MBA_ADD((ctx).r7, (ctx).r0), MBA_SUB((ctx).r1, (ctx).r2)); (ctx).pc++; break; \
                case 72: (ctx).r0 = MBA_NOT(MBA_AND((ctx).r0, (ctx).r1)); (ctx).r0 ^= (ctx).r2; (ctx).pc++; break; \
                case 73: (ctx).r1 = MBA_XOR(MBA_OR((ctx).r1, (ctx).r2), MBA_AND((ctx).r3, (ctx).r4)); (ctx).pc++; break; \
                case 74: (ctx).r2 = MBA_ADD(MBA_SUB((ctx).r2, (ctx).r3), MBA_XOR((ctx).r4, (ctx).r5)); (ctx).pc++; break; \
                case 75: (ctx).r3 = MBA_SUB(MBA_ADD((ctx).r3, (ctx).r4), MBA_OR((ctx).r5, (ctx).r6)); (ctx).pc++; break; \
                case 76: (ctx).r4 = MBA_OR(MBA_XOR((ctx).r4, (ctx).r5), MBA_AND((ctx).r6, (ctx).r7)); (ctx).pc++; break; \
                case 77: (ctx).r5 = MBA_AND(MBA_NOT((ctx).r5), MBA_OR((ctx).r6, (ctx).r7)); (ctx).pc++; break; \
                case 78: (ctx).r6 = MBA_XOR(MBA_ADD((ctx).r6, (ctx).r7), MBA_SUB((ctx).r0, (ctx).r1)); (ctx).pc++; break; \
                case 79: (ctx).r7 = MBA_NOT(MBA_OR((ctx).r7, (ctx).r0)); (ctx).r7 += (ctx).r1; (ctx).pc++; break; \
                case 80: (ctx).r0 ^= __rdtsc(); (ctx).pc++; break; \
                case 81: (ctx).r1 += (unsigned long long)__readgsqword(0x60); (ctx).pc++; break; \
                case 82: (ctx).r2 -= (unsigned long long)__readgsqword(0x30); (ctx).pc++; break; \
                case 83: (ctx).r3 |= __rdtsc(); (ctx).pc++; break; \
                case 84: (ctx).r4 &= (unsigned long long)__readgsqword(0x60); (ctx).pc++; break; \
                case 85: (ctx).r5 = ~__rdtsc(); (ctx).pc++; break; \
                case 86: (ctx).r6 = ((ctx).r6 << 11) | ((ctx).r6 >> 53); (ctx).r6 ^= __rdtsc(); (ctx).pc++; break; \
                case 87: (ctx).r7 = ((ctx).r7 << 13) | ((ctx).r7 >> 51); (ctx).r7 += __rdtsc(); (ctx).pc++; break; \
                case 88: (ctx).r0 = MBA_XOR((ctx).r0, __rdtsc()); (ctx).pc++; break; \
                case 89: (ctx).r1 = MBA_ADD((ctx).r1, (unsigned long long)__readgsqword(0x60)); (ctx).pc++; break; \
                case 90: (ctx).r2 = MBA_SUB((ctx).r2, (unsigned long long)__readgsqword(0x30)); (ctx).pc++; break; \
                case 91: (ctx).r3 = MBA_OR((ctx).r3, __rdtsc()); (ctx).pc++; break; \
                case 92: (ctx).r4 = MBA_AND((ctx).r4, (unsigned long long)__readgsqword(0x60)); (ctx).pc++; break; \
                case 93: (ctx).r5 = MBA_NOT(__rdtsc()); (ctx).pc++; break; \
                case 94: (ctx).r6 = ((ctx).r6 << 17) | ((ctx).r6 >> 47); (ctx).r6 ^= (unsigned long long)__readgsqword(0x30); (ctx).pc++; break; \
                case 95: (ctx).r7 = ((ctx).r7 << 19) | ((ctx).r7 >> 45); (ctx).r7 += (unsigned long long)__readgsqword(0x60); (ctx).pc++; break; \
                case 96: if ((ctx).r0 > (ctx).r1) { (ctx).r0 ^= (ctx).r1; } else { (ctx).r0 += (ctx).r1; } (ctx).pc++; break; \
                case 97: if ((ctx).r1 < (ctx).r2) { (ctx).r1 = ~(ctx).r1; } else { (ctx).r1 -= (ctx).r2; } (ctx).pc++; break; \
                case 98: if ((ctx).r2 & 0x100) { (ctx).r2 = ((ctx).r2 << 7) | ((ctx).r2 >> 57); } else { (ctx).r2 ^= (ctx).r3; } (ctx).pc++; break; \
                case 99: if ((ctx).r3 & 0x200) { (ctx).r3 = MBA_XOR((ctx).r3, (ctx).r4); } else { (ctx).r3 = MBA_ADD((ctx).r3, (ctx).r4); } (ctx).pc++; break; \
                case 100: if ((ctx).r4 > (ctx).r5) { (ctx).r4 = MBA_OR((ctx).r4, (ctx).r5); } else { (ctx).r4 = MBA_AND((ctx).r4, (ctx).r5); } (ctx).pc++; break; \
                case 101: if ((ctx).r5 < (ctx).r6) { (ctx).r5 = MBA_NOT((ctx).r5); } else { (ctx).r5 = MBA_SUB((ctx).r5, (ctx).r6); } (ctx).pc++; break; \
                case 102: if ((ctx).r6 & 0x400) { (ctx).r6 = ((ctx).r6 << 11) | ((ctx).r6 >> 53); } else { (ctx).r6 += (ctx).r7; } (ctx).pc++; break; \
                case 103: if ((ctx).r7 & 0x800) { (ctx).r7 = MBA_XOR((ctx).r7, (ctx).r0); } else { (ctx).r7 = MBA_ADD((ctx).r7, (ctx).r0); } (ctx).pc++; break; \
                case 104: (ctx).r0 = MBA_XOR(MBA_AND((ctx).r0, (ctx).r1), MBA_OR((ctx).r2, (ctx).r3)); (ctx).r0 = ((ctx).r0 << 5) | ((ctx).r0 >> 59); (ctx).pc++; break; \
                case 105: (ctx).r1 = MBA_ADD(MBA_OR((ctx).r1, (ctx).r2), MBA_AND((ctx).r3, (ctx).r4)); (ctx).r1 = ((ctx).r1 << 9) | ((ctx).r1 >> 55); (ctx).pc++; break; \
                case 106: (ctx).r2 = MBA_SUB(MBA_XOR((ctx).r2, (ctx).r3), MBA_ADD((ctx).r4, (ctx).r5)); (ctx).r2 = ((ctx).r2 << 15) | ((ctx).r2 >> 49); (ctx).pc++; break; \
                case 107: (ctx).r3 = MBA_OR(MBA_SUB((ctx).r3, (ctx).r4), MBA_XOR((ctx).r5, (ctx).r6)); (ctx).r3 = ((ctx).r3 << 21) | ((ctx).r3 >> 43); (ctx).pc++; break; \
                case 108: (ctx).r4 = MBA_AND(MBA_ADD((ctx).r4, (ctx).r5), MBA_NOT((ctx).r6)); (ctx).r4 ^= (ctx).r7; (ctx).pc++; break; \
                case 109: (ctx).r5 = MBA_NOT(MBA_OR((ctx).r5, (ctx).r6)); (ctx).r5 = MBA_XOR((ctx).r5, MBA_AND((ctx).r7, (ctx).r0)); (ctx).pc++; break; \
                case 110: (ctx).r6 = MBA_XOR(MBA_SUB((ctx).r6, (ctx).r7), MBA_OR((ctx).r0, (ctx).r1)); (ctx).r6 = ((ctx).r6 << 27) | ((ctx).r6 >> 37); (ctx).pc++; break; \
                case 111: (ctx).r7 = MBA_ADD(MBA_AND((ctx).r7, (ctx).r0), MBA_SUB((ctx).r1, (ctx).r2)); (ctx).r7 = MBA_NOT((ctx).r7); (ctx).pc++; break; \
                case 112: (ctx).r0 = MBA_OR(MBA_NOT((ctx).r0), MBA_XOR((ctx).r1, (ctx).r2)); (ctx).r0 += (ctx).r3; (ctx).pc++; break; \
                case 113: (ctx).r1 = MBA_SUB(MBA_XOR((ctx).r1, (ctx).r2), MBA_OR((ctx).r3, (ctx).r4)); (ctx).r1 = ((ctx).r1 << 31) | ((ctx).r1 >> 33); (ctx).pc++; break; \
                case 114: (ctx).r2 = MBA_AND(MBA_ADD((ctx).r2, (ctx).r3), MBA_NOT((ctx).r4)); (ctx).r2 ^= (ctx).r5; (ctx).pc++; break; \
                case 115: (ctx).r3 = MBA_XOR(MBA_OR((ctx).r3, (ctx).r4), MBA_AND((ctx).r5, (ctx).r6)); (ctx).r3 = MBA_NOT((ctx).r3); (ctx).pc++; break; \
                case 116: (ctx).r4 = MBA_ADD(MBA_NOT((ctx).r4), MBA_SUB((ctx).r5, (ctx).r6)); (ctx).r4 = MBA_XOR((ctx).r4, (ctx).r7); (ctx).pc++; break; \
                case 117: (ctx).r5 = MBA_OR(MBA_AND((ctx).r5, (ctx).r6), MBA_XOR((ctx).r7, (ctx).r0)); (ctx).r5 = ((ctx).r5 << 3) | ((ctx).r5 >> 61); (ctx).pc++; break; \
                case 118: (ctx).r6 = MBA_NOT(MBA_ADD((ctx).r6, (ctx).r7)); (ctx).r6 = MBA_OR((ctx).r6, MBA_AND((ctx).r0, (ctx).r1)); (ctx).pc++; break; \
                case 119: (ctx).r7 = MBA_XOR(MBA_SUB((ctx).r7, (ctx).r0), MBA_ADD((ctx).r1, (ctx).r2)); (ctx).r7 = MBA_NOT((ctx).r7); (ctx).pc++; break; \
                case 120: (ctx).r0 = MBA_AND(MBA_OR((ctx).r0, (ctx).r1), MBA_XOR((ctx).r2, (ctx).r3)); (ctx).r0 = ((ctx).r0 << 13) | ((ctx).r0 >> 51); (ctx).pc++; break; \
                case 121: (ctx).r1 = MBA_SUB(MBA_AND((ctx).r1, (ctx).r2), MBA_OR((ctx).r3, (ctx).r4)); (ctx).r1 = MBA_NOT((ctx).r1); (ctx).pc++; break; \
                case 122: (ctx).r2 = MBA_XOR(MBA_NOT((ctx).r2), MBA_ADD((ctx).r3, (ctx).r4)); (ctx).r2 += (ctx).r5; (ctx).pc++; break; \
                case 123: (ctx).r3 = MBA_OR(MBA_XOR((ctx).r3, (ctx).r4), MBA_SUB((ctx).r5, (ctx).r6)); (ctx).r3 = ((ctx).r3 << 17) | ((ctx).r3 >> 47); (ctx).pc++; break; \
                case 124: (ctx).r4 = MBA_ADD(MBA_OR((ctx).r4, (ctx).r5), MBA_AND((ctx).r6, (ctx).r7)); (ctx).r4 = MBA_NOT((ctx).r4); (ctx).pc++; break; \
                case 125: (ctx).r5 = MBA_NOT(MBA_SUB((ctx).r5, (ctx).r6)); (ctx).r5 = MBA_XOR((ctx).r5, MBA_OR((ctx).r7, (ctx).r0)); (ctx).pc++; break; \
                case 126: (ctx).r6 = MBA_AND(MBA_ADD((ctx).r6, (ctx).r7), MBA_NOT((ctx).r0)); (ctx).r6 ^= (ctx).r1; (ctx).pc++; break; \
                case 127: (ctx).r7 = MBA_XOR(MBA_OR((ctx).r7, (ctx).r0), MBA_AND((ctx).r1, (ctx).r2)); (ctx).r7 = ((ctx).r7 << 23) | ((ctx).r7 >> 41); (ctx).pc++; break; \
                default: \
                    (ctx).r0 ^= (ctx).r1; \
                    (ctx).r1 += (ctx).r2; \
                    (ctx).r2 -= (ctx).r3; \
                    (ctx).r3 |= (ctx).r4; \
                    (ctx).r4 &= (ctx).r5; \
                    (ctx).r5 = ~(ctx).r6; \
                    (ctx).r6 = ((ctx).r6 << 7) | ((ctx).r6 >> 57); \
                    (ctx).r7 = ((ctx).r7 << 11) | ((ctx).r7 >> 53); \
                    (ctx).pc++; \
                    break; \
            } \
        } \
    } while (0)

struct VMContext { \
    volatile unsigned long long r0, r1, r2, r3, r4, r5, r6, r7; \
    volatile unsigned long long pc; \
    volatile unsigned long long flags; \
};

#define MEGA_888888888888X(...) \
    do { \
        struct VMContext _vm_ctx; \
        VM_CONTEXT_INIT(_vm_ctx, 1337); \
        VM_EXECUTE_GRAPH(_vm_ctx, 64); \
        GRAPH_POLYMORPHIC_LAYER_1((_vm_ctx.r0 ^ _vm_ctx.r1), _vm_ctx.r0, _vm_ctx.r1, _vm_ctx.r2, _vm_ctx.r3); \
        GRAPH_POLYMORPHIC_LAYER_1((_vm_ctx.r2 ^ _vm_ctx.r3), _vm_ctx.r2, _vm_ctx.r3, _vm_ctx.r4, _vm_ctx.r5); \
        GRAPH_POLYMORPHIC_LAYER_1((_vm_ctx.r4 ^ _vm_ctx.r5), _vm_ctx.r4, _vm_ctx.r5, _vm_ctx.r6, _vm_ctx.r7); \
        VM_EXECUTE_GRAPH(_vm_ctx, 32); \
        BRKIDA_EXTREME; \
        POLYMORPHIC_HEAVY(); \
    } while (0)

#endif
