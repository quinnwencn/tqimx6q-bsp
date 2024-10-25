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
	{ 0x218ac1f0, __VMLINUX_SYMBOL_STR(kill_litter_super) },
	{ 0xaba4fc69, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0xc21996c7, __VMLINUX_SYMBOL_STR(default_llseek) },
	{ 0x9f6e3ac1, __VMLINUX_SYMBOL_STR(simple_statfs) },
	{ 0x9577f9a5, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0xc46486f6, __VMLINUX_SYMBOL_STR(unregister_binfmt) },
	{ 0xbb95f3a4, __VMLINUX_SYMBOL_STR(__register_binfmt) },
	{ 0xd071e461, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x242a37c3, __VMLINUX_SYMBOL_STR(iput) },
	{ 0xe14d1eb8, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0xd03e4bf0, __VMLINUX_SYMBOL_STR(simple_pin_fs) },
	{ 0xccf7eefc, __VMLINUX_SYMBOL_STR(current_fs_time) },
	{ 0xe953b21f, __VMLINUX_SYMBOL_STR(get_next_ino) },
	{ 0x4449f71a, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0x9592b0d2, __VMLINUX_SYMBOL_STR(lookup_one_len) },
	{ 0xc8339e24, __VMLINUX_SYMBOL_STR(string_unescape) },
	{ 0x20000329, __VMLINUX_SYMBOL_STR(simple_strtoul) },
	{ 0x349cba85, __VMLINUX_SYMBOL_STR(strchr) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0xcdc49e19, __VMLINUX_SYMBOL_STR(lockref_get) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x97255bdf, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0xdc1a78c, __VMLINUX_SYMBOL_STR(bin2hex) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0x528c709d, __VMLINUX_SYMBOL_STR(simple_read_from_buffer) },
	{ 0xd58f6c4, __VMLINUX_SYMBOL_STR(simple_release_fs) },
	{ 0x4af62306, __VMLINUX_SYMBOL_STR(dput) },
	{ 0x6aef35b5, __VMLINUX_SYMBOL_STR(d_drop) },
	{ 0x1c7a5341, __VMLINUX_SYMBOL_STR(drop_nlink) },
	{ 0xdfd61436, __VMLINUX_SYMBOL_STR(_raw_write_unlock) },
	{ 0xd100acbd, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0xfbc74f64, __VMLINUX_SYMBOL_STR(__copy_from_user) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xeb344ee4, __VMLINUX_SYMBOL_STR(clear_inode) },
	{ 0x77fd492a, __VMLINUX_SYMBOL_STR(simple_fill_super) },
	{ 0xf89cc8e, __VMLINUX_SYMBOL_STR(mount_single) },
	{ 0xb46c8ce5, __VMLINUX_SYMBOL_STR(kernel_read) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xdd771b9c, __VMLINUX_SYMBOL_STR(would_dump) },
	{ 0x511f9e6b, __VMLINUX_SYMBOL_STR(fd_install) },
	{ 0xa843805a, __VMLINUX_SYMBOL_STR(get_unused_fd_flags) },
	{ 0xdcb0349b, __VMLINUX_SYMBOL_STR(sys_close) },
	{ 0x6639d793, __VMLINUX_SYMBOL_STR(search_binary_handler) },
	{ 0x96b077d1, __VMLINUX_SYMBOL_STR(prepare_binprm) },
	{ 0x7a504a3e, __VMLINUX_SYMBOL_STR(open_exec) },
	{ 0xdf7dcf98, __VMLINUX_SYMBOL_STR(bprm_change_interp) },
	{ 0xd6fd9566, __VMLINUX_SYMBOL_STR(copy_strings_kernel) },
	{ 0x952e3947, __VMLINUX_SYMBOL_STR(fput) },
	{ 0x3934ba4f, __VMLINUX_SYMBOL_STR(remove_arg_zero) },
	{ 0x4bc9fa80, __VMLINUX_SYMBOL_STR(_raw_read_unlock) },
	{ 0x73e20c1c, __VMLINUX_SYMBOL_STR(strlcpy) },
	{ 0xe2d5255a, __VMLINUX_SYMBOL_STR(strcmp) },
	{ 0x9f984513, __VMLINUX_SYMBOL_STR(strrchr) },
	{ 0xb5198b77, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D2B5D202BA235ED4DE4D79C");
