#include <linux/module.h>

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("hikalium <hikalium@hikalium.com>");
MODULE_DESCRIPTION("Disable CPU Caches using CR0.CD");

uint32_t ReadCR0(void);
void WriteCR0(uint32_t);

#define CR0_CD (1 << 30)

static int mymodule_init(void) {
 uint32_t cr0 = ReadCR0();
 printk(KERN_ALERT "CR0: 0x%08X\n", cr0);
 printk(KERN_ALERT "Set CR0.CD...\n");
 cr0 |= CR0_CD;
 WriteCR0(cr0);
 printk(KERN_ALERT "CR0: 0x%08X\n", ReadCR0());
 return 0;
}
static void mymodule_exit(void) {
 uint32_t cr0 = ReadCR0();
 printk(KERN_ALERT "CR0: 0x%08X\n", cr0);
 printk(KERN_ALERT "Clear CR0.CD...\n");
 cr0 &= ~CR0_CD;
 WriteCR0(cr0);
 printk(KERN_ALERT "CR0: 0x%08X\n", ReadCR0());
}
module_init(mymodule_init);
module_exit(mymodule_exit);
