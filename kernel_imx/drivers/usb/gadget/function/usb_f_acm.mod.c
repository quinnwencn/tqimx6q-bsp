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
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x66ec8320, __VMLINUX_SYMBOL_STR(usb_gstrings_attach) },
	{ 0x931a543c, __VMLINUX_SYMBOL_STR(usb_free_all_descriptors) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0xab42497b, __VMLINUX_SYMBOL_STR(gserial_connect) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x64cb79ba, __VMLINUX_SYMBOL_STR(usb_function_unregister) },
	{ 0x835b9803, __VMLINUX_SYMBOL_STR(usb_put_function_instance) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xb479c7d0, __VMLINUX_SYMBOL_STR(usb_ep_autoconfig) },
	{ 0x4cdfb1a7, __VMLINUX_SYMBOL_STR(gserial_disconnect) },
	{ 0x2dae7baf, __VMLINUX_SYMBOL_STR(gs_alloc_req) },
	{ 0x8f1d669d, __VMLINUX_SYMBOL_STR(config_group_init_type_name) },
	{ 0x33bfdca2, __VMLINUX_SYMBOL_STR(gserial_alloc_line) },
	{ 0x88d00919, __VMLINUX_SYMBOL_STR(usb_function_register) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xcb07e30a, __VMLINUX_SYMBOL_STR(config_ep_by_speed) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xb6652875, __VMLINUX_SYMBOL_STR(gserial_free_line) },
	{ 0xfb2c9ddd, __VMLINUX_SYMBOL_STR(usb_assign_descriptors) },
	{ 0xef99b68e, __VMLINUX_SYMBOL_STR(usb_interface_id) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0xfe6e13df, __VMLINUX_SYMBOL_STR(gs_free_req) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=libcomposite,u_serial";


MODULE_INFO(srcversion, "2CEB980585820920DBE4F45");
