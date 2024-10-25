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
	{ 0x76bef8c9, __VMLINUX_SYMBOL_STR(ethtool_op_get_link) },
	{ 0xdcc663bc, __VMLINUX_SYMBOL_STR(eth_change_mtu) },
	{ 0x1c8456b8, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x2e177810, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x71b5575, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0xc2dffefe, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0xeac168b1, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xb9e34170, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x9545af6d, __VMLINUX_SYMBOL_STR(tasklet_init) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x4f19ee41, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0x1a1431fd, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irq) },
	{ 0x3507a132, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x39e32ba4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0x9b21441b, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0xd7476198, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_irq) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0x37cb90e0, __VMLINUX_SYMBOL_STR(usb_unlink_urb) },
	{ 0x21867382, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xd973ff2e, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xc50571aa, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xc64d2885, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0x51124f1a, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x1de347a6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xbace055, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0xa394b066, __VMLINUX_SYMBOL_STR(netif_device_detach) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0x8ed410b4, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xcb564cd2, __VMLINUX_SYMBOL_STR(netif_rx) },
	{ 0xed8c6ae4, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0xddbf96fd, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x6128b5fc, __VMLINUX_SYMBOL_STR(__printk_ratelimit) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDAp8150d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p0012d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v3980p0003d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p401Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1557p8150d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0586p401Ad*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "513BFA538BC3A7F25A96AB9");
