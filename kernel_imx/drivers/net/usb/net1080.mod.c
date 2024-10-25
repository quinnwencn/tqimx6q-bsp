#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x51e8a657, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xdb1b12d, __VMLINUX_SYMBOL_STR(usbnet_resume) },
	{ 0x9419228a, __VMLINUX_SYMBOL_STR(usbnet_suspend) },
	{ 0xecb07420, __VMLINUX_SYMBOL_STR(usbnet_disconnect) },
	{ 0xf1a1f292, __VMLINUX_SYMBOL_STR(usbnet_probe) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xa18e743c, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0x4dcd620, __VMLINUX_SYMBOL_STR(usbnet_write_cmd) },
	{ 0xe1e0dbef, __VMLINUX_SYMBOL_STR(usbnet_read_cmd) },
	{ 0x3daff5d4, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0x1df28c1f, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x8194dc8c, __VMLINUX_SYMBOL_STR(usbnet_write_cmd_async) },
	{ 0x7cf2d5b9, __VMLINUX_SYMBOL_STR(usbnet_get_endpoints) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x99bb8806, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x826cf7d0, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x15652ebb, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x81607f44, __VMLINUX_SYMBOL_STR(skb_copy_expand) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0525p1080d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v06D0p0622d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "EFF27B20292EA2953ACFB09");
