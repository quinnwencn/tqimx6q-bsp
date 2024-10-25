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
	{ 0x716dcac3, __VMLINUX_SYMBOL_STR(gether_get_qmult) },
	{ 0x8dbf1832, __VMLINUX_SYMBOL_STR(gether_setup_name_default) },
	{ 0x2b1ff963, __VMLINUX_SYMBOL_STR(gether_get_host_addr_cdc) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xf3b5db55, __VMLINUX_SYMBOL_STR(gether_get_ifname) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x8878cfa6, __VMLINUX_SYMBOL_STR(gether_cleanup) },
	{ 0x64cb79ba, __VMLINUX_SYMBOL_STR(usb_function_unregister) },
	{ 0x9ad4b5f6, __VMLINUX_SYMBOL_STR(gether_set_host_addr) },
	{ 0xf4726980, __VMLINUX_SYMBOL_STR(gether_get_dev_addr) },
	{ 0x24fb0494, __VMLINUX_SYMBOL_STR(gether_connect) },
	{ 0x835b9803, __VMLINUX_SYMBOL_STR(usb_put_function_instance) },
	{ 0x5a5a94a6, __VMLINUX_SYMBOL_STR(kstrtou8) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf8a23b0d, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0xb479c7d0, __VMLINUX_SYMBOL_STR(usb_ep_autoconfig) },
	{ 0xc2dffefe, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x7aae7fac, __VMLINUX_SYMBOL_STR(gether_set_gadget) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x22fa129b, __VMLINUX_SYMBOL_STR(gether_get_host_addr) },
	{ 0x8f1d669d, __VMLINUX_SYMBOL_STR(config_group_init_type_name) },
	{ 0x65bd379f, __VMLINUX_SYMBOL_STR(gether_set_qmult) },
	{ 0x88d00919, __VMLINUX_SYMBOL_STR(usb_function_register) },
	{ 0xbb546c55, __VMLINUX_SYMBOL_STR(gether_register_netdev) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x5eaaca74, __VMLINUX_SYMBOL_STR(gether_set_dev_addr) },
	{ 0xcb07e30a, __VMLINUX_SYMBOL_STR(config_ep_by_speed) },
	{ 0xe0782047, __VMLINUX_SYMBOL_STR(gether_disconnect) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xfb2c9ddd, __VMLINUX_SYMBOL_STR(usb_assign_descriptors) },
	{ 0xef99b68e, __VMLINUX_SYMBOL_STR(usb_interface_id) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=libcomposite,u_ether";


MODULE_INFO(srcversion, "5518131AA0E03DFAB6BD378");
