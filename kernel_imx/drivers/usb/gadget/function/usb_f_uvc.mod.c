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
	{ 0x65094e38, __VMLINUX_SYMBOL_STR(usb_function_deactivate) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x53331039, __VMLINUX_SYMBOL_STR(v4l2_event_unsubscribe) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x65f0bc8f, __VMLINUX_SYMBOL_STR(usb_ep_autoconfig_ss) },
	{ 0x66ec8320, __VMLINUX_SYMBOL_STR(usb_gstrings_attach) },
	{ 0x931a543c, __VMLINUX_SYMBOL_STR(usb_free_all_descriptors) },
	{ 0xc46ee7a3, __VMLINUX_SYMBOL_STR(video_device_release_empty) },
	{ 0xf56c4c39, __VMLINUX_SYMBOL_STR(v4l2_event_queue) },
	{ 0xdf0487f8, __VMLINUX_SYMBOL_STR(vb2_mmap) },
	{ 0x8a8b254b, __VMLINUX_SYMBOL_STR(v4l2_device_unregister) },
	{ 0x5c325570, __VMLINUX_SYMBOL_STR(vb2_ops_wait_prepare) },
	{ 0x770d8aec, __VMLINUX_SYMBOL_STR(__video_register_device) },
	{ 0xec6bcd50, __VMLINUX_SYMBOL_STR(config_item_init_type_name) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x64cb79ba, __VMLINUX_SYMBOL_STR(usb_function_unregister) },
	{ 0x18c2fd92, __VMLINUX_SYMBOL_STR(v4l2_device_register) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x1da7f8b3, __VMLINUX_SYMBOL_STR(usb_function_activate) },
	{ 0x3b92da9e, __VMLINUX_SYMBOL_STR(vb2_vmalloc_memops) },
	{ 0x835b9803, __VMLINUX_SYMBOL_STR(usb_put_function_instance) },
	{ 0x5a5a94a6, __VMLINUX_SYMBOL_STR(kstrtou8) },
	{ 0x51d559d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x79653f23, __VMLINUX_SYMBOL_STR(v4l2_event_subscribe) },
	{ 0xf8a23b0d, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xd8315f8f, __VMLINUX_SYMBOL_STR(video_unregister_device) },
	{ 0xb479c7d0, __VMLINUX_SYMBOL_STR(usb_ep_autoconfig) },
	{ 0x5cf55f60, __VMLINUX_SYMBOL_STR(v4l2_fh_init) },
	{ 0x8dc53c82, __VMLINUX_SYMBOL_STR(vb2_plane_vaddr) },
	{ 0xdd476579, __VMLINUX_SYMBOL_STR(vb2_buffer_done) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x9f39b1d9, __VMLINUX_SYMBOL_STR(vb2_qbuf) },
	{ 0x8f1d669d, __VMLINUX_SYMBOL_STR(config_group_init_type_name) },
	{ 0x58481cb5, __VMLINUX_SYMBOL_STR(vb2_querybuf) },
	{ 0x88d00919, __VMLINUX_SYMBOL_STR(usb_function_register) },
	{ 0x9aa551e, __VMLINUX_SYMBOL_STR(usb_composite_setup_continue) },
	{ 0x1de347a6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x21c25104, __VMLINUX_SYMBOL_STR(vb2_streamon) },
	{ 0xb55a4e2b, __VMLINUX_SYMBOL_STR(video_devdata) },
	{ 0x5ac15bae, __VMLINUX_SYMBOL_STR(kstrtou16) },
	{ 0xcb07e30a, __VMLINUX_SYMBOL_STR(config_ep_by_speed) },
	{ 0xaa4a7797, __VMLINUX_SYMBOL_STR(hex2bin) },
	{ 0xad09b52, __VMLINUX_SYMBOL_STR(vb2_reqbufs) },
	{ 0x598542b2, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xcd5406bd, __VMLINUX_SYMBOL_STR(vb2_dqbuf) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xa46f2f1b, __VMLINUX_SYMBOL_STR(kstrtouint) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x1b496ab1, __VMLINUX_SYMBOL_STR(vb2_ops_wait_finish) },
	{ 0xbe04af57, __VMLINUX_SYMBOL_STR(v4l2_fh_add) },
	{ 0xef99b68e, __VMLINUX_SYMBOL_STR(usb_interface_id) },
	{ 0x67c20849, __VMLINUX_SYMBOL_STR(v4l2_fh_del) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x84c02c01, __VMLINUX_SYMBOL_STR(vb2_poll) },
	{ 0xbbd8f406, __VMLINUX_SYMBOL_STR(vb2_queue_release) },
	{ 0x7cd8deb7, __VMLINUX_SYMBOL_STR(config_group_find_item) },
	{ 0x48002c03, __VMLINUX_SYMBOL_STR(vb2_streamoff) },
	{ 0x1c483a9, __VMLINUX_SYMBOL_STR(v4l2_get_timestamp) },
	{ 0x6b4d241b, __VMLINUX_SYMBOL_STR(video_ioctl2) },
	{ 0x6191fac7, __VMLINUX_SYMBOL_STR(v4l2_fh_exit) },
	{ 0xe8cfb50b, __VMLINUX_SYMBOL_STR(vb2_queue_init) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=libcomposite";


MODULE_INFO(srcversion, "705ABCF63D9EDE2DD3E47A8");
