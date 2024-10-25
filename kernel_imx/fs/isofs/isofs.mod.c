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
	{ 0x34c59792, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0xaadfbb0, __VMLINUX_SYMBOL_STR(iget_failed) },
	{ 0x5567130a, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xdeba29e7, __VMLINUX_SYMBOL_STR(sb_min_blocksize) },
	{ 0x107e5878, __VMLINUX_SYMBOL_STR(zlib_inflateEnd) },
	{ 0x74ef5eb, __VMLINUX_SYMBOL_STR(unload_nls) },
	{ 0xb3e2fe8d, __VMLINUX_SYMBOL_STR(save_mount_options) },
	{ 0x5fc56a46, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0xd858e6b1, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0xd6ee688f, __VMLINUX_SYMBOL_STR(vmalloc) },
	{ 0x97255bdf, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0x40c67ad1, __VMLINUX_SYMBOL_STR(page_address) },
	{ 0xa37b4a10, __VMLINUX_SYMBOL_STR(iget5_locked) },
	{ 0x1064a0, __VMLINUX_SYMBOL_STR(pagecache_get_page) },
	{ 0xacf4d843, __VMLINUX_SYMBOL_STR(match_strdup) },
	{ 0x667037c1, __VMLINUX_SYMBOL_STR(ll_rw_block) },
	{ 0xcae232b, __VMLINUX_SYMBOL_STR(utf16s_to_utf8s) },
	{ 0x44e9a829, __VMLINUX_SYMBOL_STR(match_token) },
	{ 0xfb2f8a4, __VMLINUX_SYMBOL_STR(mktime64) },
	{ 0x27dd0b6e, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0x39ed8716, __VMLINUX_SYMBOL_STR(mount_bdev) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x11839a27, __VMLINUX_SYMBOL_STR(page_symlink_inode_operations) },
	{ 0xd9d07731, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x13a8f4e2, __VMLINUX_SYMBOL_STR(__getblk_gfp) },
	{ 0x32ddd5b6, __VMLINUX_SYMBOL_STR(call_rcu) },
	{ 0x91715312, __VMLINUX_SYMBOL_STR(sprintf) },
	{ 0x5e492ddd, __VMLINUX_SYMBOL_STR(__alloc_pages_nodemask) },
	{ 0xb2308882, __VMLINUX_SYMBOL_STR(mpage_readpages) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0x5f754e5a, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x60b7eac1, __VMLINUX_SYMBOL_STR(mpage_readpage) },
	{ 0x11089ac7, __VMLINUX_SYMBOL_STR(_ctype) },
	{ 0xd627480b, __VMLINUX_SYMBOL_STR(strncat) },
	{ 0xe4435fcb, __VMLINUX_SYMBOL_STR(__bread_gfp) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x69e4e33a, __VMLINUX_SYMBOL_STR(d_obtain_alias) },
	{ 0x71c90087, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0xd81f7695, __VMLINUX_SYMBOL_STR(kunmap) },
	{ 0xce5ac24f, __VMLINUX_SYMBOL_STR(zlib_inflate_workspacesize) },
	{ 0x84b183ae, __VMLINUX_SYMBOL_STR(strncmp) },
	{ 0x3e4b9113, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0x248b0282, __VMLINUX_SYMBOL_STR(set_nlink) },
	{ 0x9c3412cb, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x25d044d5, __VMLINUX_SYMBOL_STR(__wait_on_buffer) },
	{ 0xaa09e94, __VMLINUX_SYMBOL_STR(generic_ro_fops) },
	{ 0x4e3567f7, __VMLINUX_SYMBOL_STR(match_int) },
	{ 0x6c347976, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0x8a49f10f, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0x1ebcd8bf, __VMLINUX_SYMBOL_STR(contig_page_data) },
	{ 0x581f98da, __VMLINUX_SYMBOL_STR(zlib_inflate) },
	{ 0xc6135424, __VMLINUX_SYMBOL_STR(inode_init_once) },
	{ 0xa3a248a7, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0x97475cd4, __VMLINUX_SYMBOL_STR(__free_pages) },
	{ 0x91d29912, __VMLINUX_SYMBOL_STR(kmap) },
	{ 0x93fca811, __VMLINUX_SYMBOL_STR(__get_free_pages) },
	{ 0xbf8e0af3, __VMLINUX_SYMBOL_STR(load_nls) },
	{ 0x2aa0e4fc, __VMLINUX_SYMBOL_STR(strncasecmp) },
	{ 0xa4d29841, __VMLINUX_SYMBOL_STR(unlock_new_inode) },
	{ 0x87a51522, __VMLINUX_SYMBOL_STR(kill_block_super) },
	{ 0x6f20960a, __VMLINUX_SYMBOL_STR(full_name_hash) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xdf21cf1, __VMLINUX_SYMBOL_STR(generic_show_options) },
	{ 0xf6d847ed, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0xd071e461, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x35a88f28, __VMLINUX_SYMBOL_STR(zlib_inflateInit2) },
	{ 0x4302d0eb, __VMLINUX_SYMBOL_STR(free_pages) },
	{ 0x242a37c3, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x9d669763, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0xa1ae6569, __VMLINUX_SYMBOL_STR(load_nls_default) },
	{ 0x4a56e671, __VMLINUX_SYMBOL_STR(d_splice_alias) },
	{ 0x7b45c467, __VMLINUX_SYMBOL_STR(sync_filesystem) },
	{ 0x8c1151e8, __VMLINUX_SYMBOL_STR(sb_set_blocksize) },
	{ 0xf42d0a0a, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0x3e935180, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0x6df3e29e, __VMLINUX_SYMBOL_STR(ioctl_by_bdev) },
	{ 0x9577f9a5, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x5baaffea, __VMLINUX_SYMBOL_STR(init_special_inode) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
	{ 0x676bbc0f, __VMLINUX_SYMBOL_STR(_set_bit) },
	{ 0x49ebacbd, __VMLINUX_SYMBOL_STR(_clear_bit) },
	{ 0xbff6e9ce, __VMLINUX_SYMBOL_STR(flush_dcache_page) },
	{ 0x67adc20d, __VMLINUX_SYMBOL_STR(generic_block_bmap) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7D6CAA2BD3F07E1DD424BC0");
