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
	{ 0xdf859876, __VMLINUX_SYMBOL_STR(mii_ethtool_gset) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0x50eb7ac7, __VMLINUX_SYMBOL_STR(phy_disconnect) },
	{ 0xdb1b12d, __VMLINUX_SYMBOL_STR(usbnet_resume) },
	{ 0x14137f6b, __VMLINUX_SYMBOL_STR(phy_stop) },
	{ 0xf1a1f292, __VMLINUX_SYMBOL_STR(usbnet_probe) },
	{ 0x5e439b43, __VMLINUX_SYMBOL_STR(usbnet_set_settings) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x867c2fc, __VMLINUX_SYMBOL_STR(usbnet_link_change) },
	{ 0xecb07420, __VMLINUX_SYMBOL_STR(usbnet_disconnect) },
	{ 0xf7802486, __VMLINUX_SYMBOL_STR(__aeabi_uidivmod) },
	{ 0x8ec7361a, __VMLINUX_SYMBOL_STR(generic_mii_ioctl) },
	{ 0x6ca19578, __VMLINUX_SYMBOL_STR(phy_ethtool_gset) },
	{ 0x15652ebb, __VMLINUX_SYMBOL_STR(__dev_kfree_skb_any) },
	{ 0x46865916, __VMLINUX_SYMBOL_STR(usbnet_stop) },
	{ 0xd475c1f9, __VMLINUX_SYMBOL_STR(usbnet_update_max_qlen) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xe6d56468, __VMLINUX_SYMBOL_STR(mdiobus_unregister) },
	{ 0x39e32ba4, __VMLINUX_SYMBOL_STR(__netdev_alloc_skb) },
	{ 0xfd3c02, __VMLINUX_SYMBOL_STR(phy_start_aneg) },
	{ 0x57e3638e, __VMLINUX_SYMBOL_STR(phy_print_status) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xcd4a6af4, __VMLINUX_SYMBOL_STR(usbnet_nway_reset) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x1461ed52, __VMLINUX_SYMBOL_STR(phy_start) },
	{ 0xdd47e42, __VMLINUX_SYMBOL_STR(mii_nway_restart) },
	{ 0xf299aa99, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xae84d88f, __VMLINUX_SYMBOL_STR(mdiobus_free) },
	{ 0x7cf2d5b9, __VMLINUX_SYMBOL_STR(usbnet_get_endpoints) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xba9862ef, __VMLINUX_SYMBOL_STR(usbnet_get_drvinfo) },
	{ 0x826cf7d0, __VMLINUX_SYMBOL_STR(skb_push) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x6220b4a2, __VMLINUX_SYMBOL_STR(crc32_le) },
	{ 0x45a9b57d, __VMLINUX_SYMBOL_STR(usbnet_start_xmit) },
	{ 0x9419228a, __VMLINUX_SYMBOL_STR(usbnet_suspend) },
	{ 0x8e865d3c, __VMLINUX_SYMBOL_STR(arm_delay_ops) },
	{ 0x82295d47, __VMLINUX_SYMBOL_STR(usbnet_get_link) },
	{ 0x42eff302, __VMLINUX_SYMBOL_STR(usbnet_get_settings) },
	{ 0x81607f44, __VMLINUX_SYMBOL_STR(skb_copy_expand) },
	{ 0xe1e0dbef, __VMLINUX_SYMBOL_STR(usbnet_read_cmd) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x8fea1b2, __VMLINUX_SYMBOL_STR(mdiobus_register) },
	{ 0x9a60c5b0, __VMLINUX_SYMBOL_STR(usbnet_tx_timeout) },
	{ 0x4405421d, __VMLINUX_SYMBOL_STR(kfree_skb) },
	{ 0xe94a7ec2, __VMLINUX_SYMBOL_STR(genphy_resume) },
	{ 0x9652c17c, __VMLINUX_SYMBOL_STR(usbnet_skb_return) },
	{ 0x105d536d, __VMLINUX_SYMBOL_STR(usbnet_open) },
	{ 0xa892104b, __VMLINUX_SYMBOL_STR(mii_check_media) },
	{ 0xd2680604, __VMLINUX_SYMBOL_STR(usbnet_get_msglevel) },
	{ 0xe37eea0b, __VMLINUX_SYMBOL_STR(netdev_err) },
	{ 0xbe1d0754, __VMLINUX_SYMBOL_STR(usbnet_unlink_rx_urbs) },
	{ 0x1c8456b8, __VMLINUX_SYMBOL_STR(eth_validate_addr) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x8194dc8c, __VMLINUX_SYMBOL_STR(usbnet_write_cmd_async) },
	{ 0x9e97197, __VMLINUX_SYMBOL_STR(usbnet_change_mtu) },
	{ 0xc56f3a9f, __VMLINUX_SYMBOL_STR(phy_connect) },
	{ 0xd4b32442, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x102cef6e, __VMLINUX_SYMBOL_STR(phy_mii_ioctl) },
	{ 0xcd90da80, __VMLINUX_SYMBOL_STR(phy_ethtool_sset) },
	{ 0xb81960ca, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x74e16c5b, __VMLINUX_SYMBOL_STR(mii_link_ok) },
	{ 0x99bb8806, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x3fe5bdfe, __VMLINUX_SYMBOL_STR(skb_put) },
	{ 0xb3cb52bc, __VMLINUX_SYMBOL_STR(eth_mac_addr) },
	{ 0x4dcd620, __VMLINUX_SYMBOL_STR(usbnet_write_cmd) },
	{ 0xaa3880ef, __VMLINUX_SYMBOL_STR(usbnet_set_msglevel) },
	{ 0x5f9a021e, __VMLINUX_SYMBOL_STR(mdiobus_alloc_size) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v077Bp2226d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0846p1040d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p1A00d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p1720d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07B8p420Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v08DDp90FFd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0557p2009d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p003Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0411p006Ed*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v6189p182Dd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p0056d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DF6p061Cd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07AAp0017d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1189p0893d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1631p6200d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04F1p3008d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v17EFp7203d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p772Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p7720d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p1780d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0789p0160d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v13B1p0018d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1557p7720d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v07D1p3C05d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p3C05d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v2001p1A02d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1737p0039d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v04BBp0930d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v050Dp5055d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v05ACp1402d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p772Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v14EApAB11d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0DB0pA877d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p7E2Bd*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v0B95p172Ad*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v066Bp20F9d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "FE714F923595234F122F542");
