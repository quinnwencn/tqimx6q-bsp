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
	{ 0xa18e743c, __VMLINUX_SYMBOL_STR(netdev_info) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x16e24470, __VMLINUX_SYMBOL_STR(ethtool_op_get_ts_info) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x4cd3a613, __VMLINUX_SYMBOL_STR(usb_altnum_to_altsetting) },
	{ 0xdb1b12d, __VMLINUX_SYMBOL_STR(usbnet_resume) },
	{ 0xf1a1f292, __VMLINUX_SYMBOL_STR(usbnet_probe) },
	{ 0x5e439b43, __VMLINUX_SYMBOL_STR(usbnet_set_settings) },
	{ 0x867c2fc, __VMLINUX_SYMBOL_STR(usbnet_link_change) },
	{ 0xe06f1b2, __VMLINUX_SYMBOL_STR(hrtimer_cancel) },
	{ 0xecb07420, __VMLINUX_SYMBOL_STR(usbnet_disconnect) },
	{ 0xa1d55e90, __VMLINUX_SYMBOL_STR(_raw_spin_lock_bh) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
	{ 0x2a3aa678, __VMLINUX_SYMBOL_STR(_test_and_clear_bit) },
	{ 0x15652ebb, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0xd475c1f9, __VMLINUX_SYMBOL_STR(usbnet_update_max_qlen) },
	{ 0x60ee9172, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x39e32ba4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xa85a0bc6, __VMLINUX_SYMBOL_STR(netif_schedule_queue) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xcd4a6af4, __VMLINUX_SYMBOL_STR(usbnet_nway_reset) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0x3c3fce39, __VMLINUX_SYMBOL_STR(__local_bh_enable_ip) },
	{ 0xc917e655, __VMLINUX_SYMBOL_STR(debug_smp_processor_id) },
	{ 0xe16466af, __VMLINUX_SYMBOL_STR(usb_set_interface) },
	{ 0xfaef0ed, __VMLINUX_SYMBOL_STR(__tasklet_schedule) },
	{ 0x331c2644, __VMLINUX_SYMBOL_STR(usb_driver_claim_interface) },
	{ 0xba9862ef, __VMLINUX_SYMBOL_STR(usbnet_get_drvinfo) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x45a9b57d, __VMLINUX_SYMBOL_STR(usbnet_start_xmit) },
	{ 0x9419228a, __VMLINUX_SYMBOL_STR(usbnet_suspend) },
	{ 0x82295d47, __VMLINUX_SYMBOL_STR(usbnet_get_link) },
	{ 0x82072614, __VMLINUX_SYMBOL_STR(tasklet_kill) },
	{ 0x42eff302, __VMLINUX_SYMBOL_STR(usbnet_get_settings) },
	{ 0xe1e0dbef, __VMLINUX_SYMBOL_STR(usbnet_read_cmd) },
	{ 0x1de347a6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x353629c0, __VMLINUX_SYMBOL_STR(__alloc_skb) },
	{ 0xdd3916ac, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_bh) },
	{ 0xea8dc70f, __VMLINUX_SYMBOL_STR(usbnet_get_ethernet_addr) },
	{ 0x9652c17c, __VMLINUX_SYMBOL_STR(usbnet_skb_return) },
	{ 0x428d4cf0, __VMLINUX_SYMBOL_STR(hrtimer_start) },
	{ 0xb265336a, __VMLINUX_SYMBOL_STR(usb_driver_release_interface) },
	{ 0x996bdb64, __VMLINUX_SYMBOL_STR(_kstrtoul) },
	{ 0xd2680604, __VMLINUX_SYMBOL_STR(usbnet_get_msglevel) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xbe1d0754, __VMLINUX_SYMBOL_STR(usbnet_unlink_rx_urbs) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x3197aae5, __VMLINUX_SYMBOL_STR(hrtimer_init) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0x8ed410b4, __VMLINUX_SYMBOL_STR(dev_warn) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0xfa29325, __VMLINUX_SYMBOL_STR(usb_ifnum_to_if) },
	{ 0xca54fee, __VMLINUX_SYMBOL_STR(_test_and_set_bit) },
	{ 0xf229424a, __VMLINUX_SYMBOL_STR(preempt_count_add) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xae4c3f, __VMLINUX_SYMBOL_STR(usbnet_manage_power) },
	{ 0x4dcd620, __VMLINUX_SYMBOL_STR(usbnet_write_cmd) },
	{ 0xaa3880ef, __VMLINUX_SYMBOL_STR(usbnet_set_msglevel) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v0BDBp*d*dc*dsc*dp*ic02isc0Dip00in*");
MODULE_ALIAS("usb:v413Cp*d*dc*dsc*dp*ic02isc0Dip00in*");
MODULE_ALIAS("usb:v0930p*d*dc*dsc*dp*ic02isc0Dip00in*");
MODULE_ALIAS("usb:v12D1p*d*dc*dsc*dp*ic02isc0Dip00in*");
MODULE_ALIAS("usb:v1519p0443d*dc*dsc*dp*ic02isc0Dip00in*");
MODULE_ALIAS("usb:v*p*d*dc*dsc*dp*ic02isc0Dip00in*");

MODULE_INFO(srcversion, "E0F062268CDC242B6769968");
