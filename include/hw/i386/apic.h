#ifndef APIC_H
#define APIC_H

#include "exec/hwaddr.h"

/* apic.c */
void apic_set_max_apic_id(uint32_t max_apic_id);
int apic_accept_pic_intr(DeviceState *s);
void apic_deliver_pic_intr(DeviceState *s, int level);
void apic_deliver_nmi(DeviceState *d);
int apic_get_interrupt(DeviceState *s);
int cpu_set_apic_base(DeviceState *s, uint64_t val);
uint64_t cpu_get_apic_base(DeviceState *s);
bool cpu_is_apic_enabled(DeviceState *s);
void cpu_set_apic_tpr(DeviceState *s, uint8_t val);
uint8_t cpu_get_apic_tpr(DeviceState *s);
void apic_init_reset(DeviceState *s);
void apic_sipi(DeviceState *s);
void apic_poll_irq(DeviceState *d);
void apic_designate_bsp(DeviceState *d, bool bsp);
int apic_get_highest_priority_irr(DeviceState *dev);
int apic_msr_read(int index, uint64_t *val);
int apic_msr_write(int index, uint64_t val);
bool is_x2apic_mode(DeviceState *d);

/* handle remote interrupt */
void apic_init_level_deassert(CPUState *cpu);
void apic_lapic_write(CPUState *cpu, hwaddr addr, uint32_t val);
void apic_set_irq_detour(CPUState *cpu, int vector_num, int trigger_mode);
void apic_startup(CPUState *cpu, int vector_num);

/* pc.c */
DeviceState *cpu_get_current_apic(void);

#endif
