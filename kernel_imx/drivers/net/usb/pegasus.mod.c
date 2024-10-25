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
	{ 0x60ee9172, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x62a79a6c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0x51eafc8e, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0xdcc663bc, __VMLINUX_SYMBOL_STR(eth_change_mtu) },
	{ 0x1c8456b8, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0xb3cb52bc, __VMLINUX_SYMBOL_STR(eth_mac_addr) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x2e177810, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x8e865d3c, __VMLINUX_SYMBOL_STR(arm_delay_ops) },
	{ 0x1de347a6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xeac168b1, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xc2dffefe, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x8c03d20c, __VMLINUX_SYMBOL_STR(destroy_workqueue) },
	{ 0x43a53735, __VMLINUX_SYMBOL_STR(__alloc_workqueue_key) },
	{ 0x8ed410b4, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0xfa2bcf10, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0x4f19ee41, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0xd6126fe9, __VMLINUX_SYMBOL_STR(device_set_wakeup_enable) },
	{ 0xbace055, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0x51124f1a, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x71b5575, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0x9b21441b, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0xa18e743c, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0xb9e34170, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd973ff2e, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x37cb90e0, __VMLINUX_SYMBOL_STR(usb_unlink_urb) },
	{ 0xdf859876, __VMLINUX_SYMBOL_STR(mii_ethtool_gset) },
	{ 0xe6d2b545, __VMLINUX_SYMBOL_STR(mii_ethtool_sset) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xdd47e42, __VMLINUX_SYMBOL_STR(mii_nway_restart) },
	{ 0x74e16c5b, __VMLINUX_SYMBOL_STR(mii_link_ok) },
	{ 0x21867382, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0xc50571aa, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x83130f62, __VMLINUX_SYMBOL_STR(cancel_delayed_work) },
	{ 0x9963a089, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0xc64d2885, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0xe37eea0b, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0xa394b066, __VMLINUX_SYMBOL_STR(netif_device_detach) },
	{ 0x6dcfc1a6, __VMLINUX_SYMBOL_STR(netdev_warn) },
	{ 0x39e32ba4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xcb564cd2, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0xed8c6ae4, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0xddbf96fd, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0506p4601d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0557p2007d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p110Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p4104d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p4004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p4007d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p4102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p4002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p400Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p400Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8pABC1d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p200Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v083Ap1046d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v083Ap5046d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v083ApB004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07A6p8511d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07A6p8513d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07A6p8515d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07A6p0986d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07A6p07C2d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v3334p1701d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07C9pB100d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp0121d*dc00dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp0122d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08DDp0986d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08DDp0987d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v049Fp8511d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08DDp0988d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08DDp8511d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07AAp0004d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07AAp000Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p4001d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p4002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p4102d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p400Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p200Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p4003d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001pABC1d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DB7p0002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056Ep4010d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1342p0304d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v05CCp3000d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1044p8002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0E66p400Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v03F0p811Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp0904d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp0913d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp093Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0951p000Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056Ep4002d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056Ep4005d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056Ep400Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056EpABC1d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v056Ep200Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp2202d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp2203d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp2204d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp2206d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v077Bp08B4d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp400Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp200Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p0001d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p0005d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p0009d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v045Ep007Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p1020d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B39p0109d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B39p0901d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08D1p0003d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0707p0200d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0707p0201d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v15E8p9100d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v15E8p9110d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v067Cp1001d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "2A3B9B26420207389393556");
