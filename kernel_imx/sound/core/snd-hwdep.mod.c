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
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0xaada9d65, __VMLINUX_SYMBOL_STR(snd_register_device) },
	{ 0x67c2fa54, __VMLINUX_SYMBOL_STR(__copy_to_user) },
	{ 0x4256e109, __VMLINUX_SYMBOL_STR(snd_card_file_remove) },
	{ 0x4c86184b, __VMLINUX_SYMBOL_STR(remove_wait_queue) },
	{ 0xa7843534, __VMLINUX_SYMBOL_STR(snd_device_initialize) },
	{ 0xb2e5ae4a, __VMLINUX_SYMBOL_STR(snd_lookup_minor_data) },
	{ 0x353e3fa5, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x2d50078b, __VMLINUX_SYMBOL_STR(snd_ctl_unregister_ioctl) },
	{ 0x275ef902, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xffd5a395, __VMLINUX_SYMBOL_STR(default_wake_function) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x29a1032e, __VMLINUX_SYMBOL_STR(snd_device_new) },
	{ 0x635ea8a8, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0xf8a23b0d, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0xfef80359, __VMLINUX_SYMBOL_STR(snd_unregister_device) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x8f595b11, __VMLINUX_SYMBOL_STR(snd_major) },
	{ 0x4b015768, __VMLINUX_SYMBOL_STR(snd_iprintf) },
	{ 0x2ce44480, __VMLINUX_SYMBOL_STR(module_put) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xbc10dd97, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0x8f5175eb, __VMLINUX_SYMBOL_STR(snd_card_file_add) },
	{ 0xbddb854f, __VMLINUX_SYMBOL_STR(snd_ctl_register_ioctl) },
	{ 0x359a8b67, __VMLINUX_SYMBOL_STR(put_device) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xd85cd67e, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xc7bcbc8d, __VMLINUX_SYMBOL_STR(add_wait_queue) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2f89a4e1, __VMLINUX_SYMBOL_STR(snd_info_free_entry) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0xe978873f, __VMLINUX_SYMBOL_STR(dev_set_name) },
	{ 0x63800dc7, __VMLINUX_SYMBOL_STR(snd_info_create_module_entry) },
	{ 0x30458340, __VMLINUX_SYMBOL_STR(snd_info_register) },
	{ 0xa6d172f3, __VMLINUX_SYMBOL_STR(try_module_get) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "8A3EBAAFA289AB40FF657D2");
