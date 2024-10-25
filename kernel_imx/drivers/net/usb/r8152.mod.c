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
	{ 0x1c8456b8, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0xc5df89f4, __VMLINUX_SYMBOL_STR(netdev_notice) },
	{ 0x6220b4a2, __VMLINUX_SYMBOL_STR(crc32_le) },
	{ 0x51124f1a, __VMLINUX_SYMBOL_STR(netif_carrier_on) },
	{ 0xd79d1cdb, __VMLINUX_SYMBOL_STR(mutex_trylock) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xb9e34170, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0xc64d2885, __VMLINUX_SYMBOL_STR(netif_device_attach) },
	{ 0xbace055, __VMLINUX_SYMBOL_STR(netif_carrier_off) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xdf859876, __VMLINUX_SYMBOL_STR(mii_ethtool_gset) },
	{ 0x9b21441b, __VMLINUX_SYMBOL_STR(netif_tx_wake_queue) },
	{ 0x40544e35, __VMLINUX_SYMBOL_STR(__skb_gso_segment) },
	{ 0x751a15f7, __VMLINUX_SYMBOL_STR(skb_checksum_help) },
	{ 0x44da5d0f, __VMLINUX_SYMBOL_STR(__csum_ipv6_magic) },
	{ 0x1b500651, __VMLINUX_SYMBOL_STR(pskb_expand_head) },
	{ 0xfebabc70, __VMLINUX_SYMBOL_STR(__pskb_pull_tail) },
	{ 0x15652ebb, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x9bb0460a, __VMLINUX_SYMBOL_STR(skb_copy_bits) },
	{ 0xa61d6657, __VMLINUX_SYMBOL_STR(usb_autopm_get_interface_async) },
	{ 0xa85a0bc6, __VMLINUX_SYMBOL_STR(netif_schedule_queue) },
	{ 0xc917e655, __VMLINUX_SYMBOL_STR(debug_smp_processor_id) },
	{ 0x5a6a380d, __VMLINUX_SYMBOL_STR(napi_complete_done) },
	{ 0x39e32ba4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xed8c6ae4, __VMLINUX_SYMBOL_STR(eth_type_trans) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0x6aa2d357, __VMLINUX_SYMBOL_STR(napi_gro_receive) },
	{ 0x51d559d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x598542b2, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x632780, __VMLINUX_SYMBOL_STR(work_busy) },
	{ 0xe707d823, __VMLINUX_SYMBOL_STR(__aeabi_uidiv) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xd3f93b12, __VMLINUX_SYMBOL_STR(usb_driver_set_configuration) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0xeac168b1, __VMLINUX_SYMBOL_STR(register_netdev) },
	{ 0xfa97498f, __VMLINUX_SYMBOL_STR(netif_napi_add) },
	{ 0x6b06fdce, __VMLINUX_SYMBOL_STR(delayed_work_timer_fn) },
	{ 0xfa2bcf10, __VMLINUX_SYMBOL_STR(init_timer_key) },
	{ 0xf8a23b0d, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x4f19ee41, __VMLINUX_SYMBOL_STR(alloc_etherdev_mqs) },
	{ 0x9073b95b, __VMLINUX_SYMBOL_STR(usb_reset_device) },
	{ 0x12a38747, __VMLINUX_SYMBOL_STR(usleep_range) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x4a8907de, __VMLINUX_SYMBOL_STR(cancel_delayed_work_sync) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0xa32b6202, __VMLINUX_SYMBOL_STR(napi_disable) },
	{ 0xd973ff2e, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xb62ebc32, __VMLINUX_SYMBOL_STR(skb_tstamp_tx) },
	{ 0x7d11c268, __VMLINUX_SYMBOL_STR(jiffies) },
	{ 0x9fec7104, __VMLINUX_SYMBOL_STR(skb_queue_tail) },
	{ 0x9963a089, __VMLINUX_SYMBOL_STR(queue_delayed_work_on) },
	{ 0x2d3385d3, __VMLINUX_SYMBOL_STR(system_wq) },
	{ 0xa18e743c, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0xa394b066, __VMLINUX_SYMBOL_STR(netif_device_detach) },
	{ 0xe37eea0b, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0xddbf96fd, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0xdcc663bc, __VMLINUX_SYMBOL_STR(eth_change_mtu) },
	{ 0x37cb90e0, __VMLINUX_SYMBOL_STR(usb_unlink_urb) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xdd47e42, __VMLINUX_SYMBOL_STR(mii_nway_restart) },
	{ 0x2cb2e99, __VMLINUX_SYMBOL_STR(usb_autopm_put_interface) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x77d4e7dd, __VMLINUX_SYMBOL_STR(usb_autopm_get_interface) },
	{ 0x6dcfc1a6, __VMLINUX_SYMBOL_STR(netdev_warn) },
	{ 0xf6ebc03b, __VMLINUX_SYMBOL_STR(net_ratelimit) },
	{ 0xbba98c15, __VMLINUX_SYMBOL_STR(__napi_schedule) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0x8c9149f5, __VMLINUX_SYMBOL_STR(usb_autopm_put_interface_async) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xc2dffefe, __VMLINUX_SYMBOL_STR(free_netdev) },
	{ 0x2e177810, __VMLINUX_SYMBOL_STR(unregister_netdev) },
	{ 0x3c5b3ead, __VMLINUX_SYMBOL_STR(netif_napi_del) },
	{ 0xdd3916ac, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xa1d55e90, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0x71b5575, __VMLINUX_SYMBOL_STR(consume_skb) },
	{ 0xc50571aa, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0xd6126fe9, __VMLINUX_SYMBOL_STR(device_set_wakeup_enable) },
	{ 0xe2fae716, __VMLINUX_SYMBOL_STR(kmemdup) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x21867382, __VMLINUX_SYMBOL_STR(usb_control_msg) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDAp8152d*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8152d*dc*dsc*dp*ic02isc06ip00in*");
MODULE_ALIAS("usb:v0BDAp8153d*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v0BDAp8153d*dc*dsc*dp*ic02isc06ip00in*");
MODULE_ALIAS("usb:v04E8pA101d*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v04E8pA101d*dc*dsc*dp*ic02isc06ip00in*");
MODULE_ALIAS("usb:v17EFp7205d*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v17EFp7205d*dc*dsc*dp*ic02isc06ip00in*");
MODULE_ALIAS("usb:v17EFp304Fd*dc*dsc*dp*icFFisc*ip*in*");
MODULE_ALIAS("usb:v17EFp304Fd*dc*dsc*dp*ic02isc06ip00in*");

MODULE_INFO(srcversion, "EEBA2E436A39010FE684EFD");
