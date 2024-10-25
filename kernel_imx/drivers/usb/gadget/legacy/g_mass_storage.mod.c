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
	{ 0xe4d1591e, __VMLINUX_SYMBOL_STR(fsg_config_from_params) },
	{ 0x1ccb58f7, __VMLINUX_SYMBOL_STR(fsg_common_set_num_buffers) },
	{ 0x6acb4179, __VMLINUX_SYMBOL_STR(fsg_common_set_inquiry_string) },
	{ 0xcff4bbec, __VMLINUX_SYMBOL_STR(usb_add_config) },
	{ 0x141fce2a, __VMLINUX_SYMBOL_STR(fsg_common_remove_luns) },
	{ 0xa5230df, __VMLINUX_SYMBOL_STR(fsg_common_set_nluns) },
	{ 0x2a3aa678, __VMLINUX_SYMBOL_STR(_test_and_clear_bit) },
	{ 0x60ee9172, __VMLINUX_SYMBOL_STR(param_ops_bool) },
	{ 0x82464db9, __VMLINUX_SYMBOL_STR(usb_otg_descriptor_init) },
	{ 0x9a0221c7, __VMLINUX_SYMBOL_STR(fsg_common_free_buffers) },
	{ 0x62a79a6c, __VMLINUX_SYMBOL_STR(param_ops_charp) },
	{ 0xb2ce7668, __VMLINUX_SYMBOL_STR(fsg_common_set_cdev) },
	{ 0x835b9803, __VMLINUX_SYMBOL_STR(usb_put_function_instance) },
	{ 0x266bb6bc, __VMLINUX_SYMBOL_STR(usb_otg_descriptor_alloc) },
	{ 0xf033383d, __VMLINUX_SYMBOL_STR(usb_composite_overwrite_options) },
	{ 0x1de347a6, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x4b81d97f, __VMLINUX_SYMBOL_STR(usb_composite_probe) },
	{ 0xa67695a, __VMLINUX_SYMBOL_STR(usb_add_function) },
	{ 0xd3ae3b65, __VMLINUX_SYMBOL_STR(fsg_common_create_luns) },
	{ 0x176dd54, __VMLINUX_SYMBOL_STR(usb_put_function) },
	{ 0x1821a393, __VMLINUX_SYMBOL_STR(usb_composite_unregister) },
	{ 0x265739df, __VMLINUX_SYMBOL_STR(usb_get_function) },
	{ 0x9dc025a5, __VMLINUX_SYMBOL_STR(fsg_common_free_luns) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x8717676a, __VMLINUX_SYMBOL_STR(usb_string_ids_tab) },
	{ 0x1f54e93d, __VMLINUX_SYMBOL_STR(param_array_ops) },
	{ 0x51707c29, __VMLINUX_SYMBOL_STR(fsg_common_run_thread) },
	{ 0x8abc1d96, __VMLINUX_SYMBOL_STR(usb_get_function_instance) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x7e26d4a5, __VMLINUX_SYMBOL_STR(fsg_common_set_sysfs) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0xb225bf0d, __VMLINUX_SYMBOL_STR(param_ops_ushort) },
	{ 0x149c7752, __VMLINUX_SYMBOL_STR(param_ops_uint) },
	{ 0xd468f882, __VMLINUX_SYMBOL_STR(fsg_common_set_ops) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=usb_f_mass_storage,libcomposite";


MODULE_INFO(srcversion, "69E7D36DF5C32E05A8EA3CD");
