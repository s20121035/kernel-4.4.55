#ifndef __MACH_ROCKCHIP_CPU_H
#define __MACH_ROCKCHIP_CPU_H

extern unsigned long rockchip_soc_id;

static inline bool cpu_is_rockchip(void)
{
	return rockchip_soc_id;
}

#define ROCKCHIP_CPU_VERION_MASK	0x0000f000
#define ROCKCHIP_CPU_VERION_SHIFT	12

static inline unsigned long rockchip_get_cpu_version(void)
{
	return (rockchip_soc_id & ROCKCHIP_CPU_VERION_MASK)
		>> ROCKCHIP_CPU_VERION_SHIFT;
}

static inline void rockchip_set_cpu_version(unsigned long ver)
{
	rockchip_soc_id &= ~ROCKCHIP_CPU_VERION_MASK;
	rockchip_soc_id |=
		(ver << ROCKCHIP_CPU_VERION_SHIFT) & ROCKCHIP_CPU_VERION_MASK;
}

#define ROCKCHIP_CPU_MASK       0xffff0000
#define ROCKCHIP_CPU_RK2928     0x29280000
#define ROCKCHIP_CPU_RK3026     0x30260000
#define ROCKCHIP_CPU_RK312X     0x31260000
#define ROCKCHIP_CPU_RK3036     0x30360000
#define ROCKCHIP_CPU_RK30XX     0x30660000
#define ROCKCHIP_CPU_RK3066B    0x31680000
#define ROCKCHIP_CPU_RK3188     0x31880000
#define ROCKCHIP_CPU_RK319X     0x31900000
#define ROCKCHIP_CPU_RK3288     0x32880000
#define ROCKCHIP_CPU_RK3228     0x32280000

#ifdef CONFIG_ARM
#define ROCKCHIP_CPU(id, ID) \
static inline bool cpu_is_rk##id(void) \
{ \
	return (rockchip_soc_id & ROCKCHIP_CPU_MASK) == ROCKCHIP_CPU_RK ##ID; \
}
#else
#define ROCKCHIP_CPU(id, ID) \
static inline bool cpu_is_rk##id(void) { return false; }
#endif

ROCKCHIP_CPU(2928, 2928)
ROCKCHIP_CPU(3026, 3026)
ROCKCHIP_CPU(3036, 3036)
ROCKCHIP_CPU(30xx, 30XX)
ROCKCHIP_CPU(3066b, 3066B)
ROCKCHIP_CPU(312x, 312X)
ROCKCHIP_CPU(3188, 3188)
ROCKCHIP_CPU(319x, 319X)
ROCKCHIP_CPU(3288, 3288)
ROCKCHIP_CPU(3228, 3228)

#define ROCKCHIP_SOC_MASK	(ROCKCHIP_CPU_MASK | 0xff)
#define ROCKCHIP_SOC_RK2926     (ROCKCHIP_CPU_RK2928 | 0x00)
#define ROCKCHIP_SOC_RK2928G    (ROCKCHIP_CPU_RK2928 | 0x01)
#define ROCKCHIP_SOC_RK2928L    (ROCKCHIP_CPU_RK2928 | 0x02)
#define ROCKCHIP_SOC_RK3028A    (ROCKCHIP_CPU_RK3026 | 0x03)
#define ROCKCHIP_SOC_RK3026     (ROCKCHIP_CPU_RK3026 | 0x04)
#define ROCKCHIP_SOC_RK3126     (ROCKCHIP_CPU_RK312X | 0x00)
#define ROCKCHIP_SOC_RK3126B    (ROCKCHIP_CPU_RK312X | 0x10)
#define ROCKCHIP_SOC_RK3128     (ROCKCHIP_CPU_RK312X | 0x01)
#define ROCKCHIP_SOC_RK3036     (ROCKCHIP_CPU_RK3036 | 0x00)
#define ROCKCHIP_SOC_RK3000     (ROCKCHIP_CPU_RK30XX | 0x00)
#define ROCKCHIP_SOC_RK3066     (ROCKCHIP_CPU_RK30XX | 0x01)
#define ROCKCHIP_SOC_RK3068     (ROCKCHIP_CPU_RK30XX | 0x02)
#define ROCKCHIP_SOC_RK3066B    (ROCKCHIP_CPU_RK3066B| 0x00)
#define ROCKCHIP_SOC_RK3168     (ROCKCHIP_CPU_RK3066B| 0x01)
#define ROCKCHIP_SOC_RK3028     (ROCKCHIP_CPU_RK3066B| 0x03)
#define ROCKCHIP_SOC_RK3188     (ROCKCHIP_CPU_RK3188 | 0x00)
#define ROCKCHIP_SOC_RK3188PLUS (ROCKCHIP_CPU_RK3188 | 0x10)
#define ROCKCHIP_SOC_RK3190     (ROCKCHIP_CPU_RK319X | 0x00)
#define ROCKCHIP_SOC_RK3288     (ROCKCHIP_CPU_RK3288 | 0x00)
#define ROCKCHIP_SOC_RK3228     (ROCKCHIP_CPU_RK3228 | 0x00)

#ifdef CONFIG_ARM
#define ROCKCHIP_SOC(id, ID) \
static inline bool soc_is_rk##id(void) \
{ \
	return (rockchip_soc_id & ROCKCHIP_SOC_MASK) == ROCKCHIP_SOC_RK ##ID; \
}
#else
#define ROCKCHIP_SOC(id, ID) \
static inline bool soc_is_rk##id(void) { return false; }
#endif

ROCKCHIP_SOC(2926, 2926)
ROCKCHIP_SOC(2928g, 2928G)
ROCKCHIP_SOC(2928l, 2928L)
ROCKCHIP_SOC(3028a, 3028A)
ROCKCHIP_SOC(3026, 3026)
ROCKCHIP_SOC(3126, 3126)
ROCKCHIP_SOC(3126b, 3126B)
ROCKCHIP_SOC(3128, 3128)
ROCKCHIP_SOC(3036, 3036)
ROCKCHIP_SOC(3000, 3000)
ROCKCHIP_SOC(3066, 3066)
ROCKCHIP_SOC(3068, 3068)
ROCKCHIP_SOC(3066b, 3066B)
ROCKCHIP_SOC(3168, 3168)
ROCKCHIP_SOC(3028, 3028)
ROCKCHIP_SOC(3188, 3188)
ROCKCHIP_SOC(3188plus, 3188PLUS)
ROCKCHIP_SOC(3190, 3190)
ROCKCHIP_SOC(3288, 3288)
ROCKCHIP_SOC(3228, 3228)

#endif
