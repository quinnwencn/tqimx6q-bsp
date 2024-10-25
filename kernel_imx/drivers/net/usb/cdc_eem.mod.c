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
	{ 0xb265336a, __VMLINUX_SYMBOL_STR(usb_driver_release_interface) },
	{ 0x7cf2d5b9, __VMLINUX_SYMBOL_STR(usbnet_get_endpoints) },
	{ 0x6dcfc1a6, __VMLINUX_SYMBOL_STR(netdev_warn) },
	{ 0xddbf96fd, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xb9e34170, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xc98f59e7, __VMLINUX_SYMBOL_STR(usbnet_device_suggests_idle) },
	{ 0x1df28c1f, __VMLINUX_SYMBOL_STR(skb_pull) },
	{ 0x9652c17c, __VMLINUX_SYMBOL_STR(usbnet_skb_return) },
	{ 0x3daff5d4, __VMLINUX_SYMBOL_STR(skb_trim) },
	{ 0x738c6b16, __VMLINUX_SYMBOL_STR(skb_clone) },
	{ 0xd973ff2e, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x71b5575, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x99bb8806, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x826cf7d0, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x6220b4a2, __VMLINUX_SYMBOL_STR(crc32_le) },
	{ 0x15652ebb, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x81607f44, __VMLINUX_SYMBOL_STR(skb_copy_expand) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v*p*d*dc*dsc*dp*ic02isc0Cip07in*");

MODULE_INFO(srcversion, "07A97BE75F2F8E124A49096");
