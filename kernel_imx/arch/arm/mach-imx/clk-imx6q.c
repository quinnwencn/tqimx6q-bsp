/*
 * Copyright 2011-2016 Freescale Semiconductor, Inc.
 * Copyright 2011 Linaro Ltd.
 *
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

#include <linux/init.h>
#include <linux/types.h>
#include <linux/clk.h>
#include <linux/clkdev.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <dt-bindings/clock/imx6qdl-clock.h>

#include "clk.h"
#include "common.h"
#include "hardware.h"

static const char *step_sels[]	= { "osc", "pll2_pfd2_396m", };
static const char *pll1_sw_sels[]	= { "pll1_sys", "step", };
static const char *periph_pre_sels[]	= { "pll2_bus", "pll2_pfd2_396m", "pll2_pfd0_352m", "pll2_198m", };
static const char *periph_clk2_sels[]	= { "pll3_usb_otg", "osc", "osc", "dummy", };
static const char *periph2_clk2_sels[]	= { "pll3_usb_otg", "pll2_bus", };
static const char *periph_sels[]	= { "periph_pre", "periph_clk2", };
static const char *periph2_sels[]	= { "periph2_pre", "periph2_clk2", };
static const char *axi_alt_sels[]	= { "pll2_pfd2_396m", "pll3_pfd1_540m", };
static const char *axi_sels[]		= { "periph", "axi_alt_sel", };
static const char *audio_sels[]	= { "pll4_audio_div", "pll3_pfd2_508m", "pll3_pfd3_454m", "pll3_usb_otg", };
static const char *gpu_axi_sels[]	= { "axi", "ahb", };
static const char *pre_axi_sels[]	= { "axi", "ahb", };
static const char *gpu2d_core_sels[]	= { "axi", "pll3_usb_otg", "pll2_pfd0_352m", "pll2_pfd2_396m", };
static const char *gpu2d_core_sels_2[]	= { "mmdc_ch0_axi", "pll3_usb_otg", "pll2_pfd1_594m", "pll3_pfd0_720m", };
static const char *gpu3d_core_sels[]	= { "mmdc_ch0_axi", "pll3_usb_otg", "pll2_pfd1_594m", "pll2_pfd2_396m", };
static const char *gpu3d_shader_sels[] = { "mmdc_ch0_axi", "pll3_usb_otg", "pll2_pfd1_594m", "pll3_pfd0_720m", };
static const char *ipu_sels[]		= { "mmdc_ch0_axi", "pll2_pfd2_396m", "pll3_120m", "pll3_pfd1_540m", };
static const char *ldb_di_sels[]	= { "pll5_video_div", "pll2_pfd0_352m", "pll2_pfd2_396m", "mmdc_ch1_axi", "pll3_usb_otg", };
static const char *ldb_di0_div_sels[]	= { "ldb_di0_div_3_5", "ldb_di0_div_7", };
static const char *ldb_di1_div_sels[]	= { "ldb_di1_div_3_5", "ldb_di1_div_7", };
static const char *ipu_di_pre_sels[]	= { "mmdc_ch0_axi", "pll3_usb_otg", "pll5_video_div", "pll2_pfd0_352m", "pll2_pfd2_396m", "pll3_pfd1_540m", };
static const char *ipu1_di0_sels[]	= { "ipu1_di0_pre", "dummy", "dummy", "ldb_di0", "ldb_di1", };
static const char *ipu1_di1_sels[]	= { "ipu1_di1_pre", "dummy", "dummy", "ldb_di0", "ldb_di1", };
static const char *ipu2_di0_sels[]	= { "ipu2_di0_pre", "dummy", "dummy", "ldb_di0", "ldb_di1", };
static const char *ipu2_di1_sels[]	= { "ipu2_di1_pre", "dummy", "dummy", "ldb_di0", "ldb_di1", };
static const char *ipu1_di0_sels_2[]	= { "ipu1_di0_pre", "dummy", "dummy", "ldb_di0_div_sel", "ldb_di1_div_sel", };
static const char *ipu1_di1_sels_2[]	= { "ipu1_di1_pre", "dummy", "dummy", "ldb_di0_div_sel", "ldb_di1_div_sel", };
static const char *ipu2_di0_sels_2[]	= { "ipu2_di0_pre", "dummy", "dummy", "ldb_di0_div_sel", "ldb_di1_div_sel", };
static const char *ipu2_di1_sels_2[]	= { "ipu2_di1_pre", "dummy", "dummy", "ldb_di0_div_sel", "ldb_di1_div_sel", };
static const char *hsi_tx_sels[]	= { "pll3_120m", "pll2_pfd2_396m", };
static const char *pcie_axi_sels[]	= { "axi", "ahb", };
static const char *ssi_sels[]		= { "pll3_pfd2_508m", "pll3_pfd3_454m", "pll4_audio_div", };
static const char *usdhc_sels[]	= { "pll2_pfd2_396m", "pll2_pfd0_352m", };
static const char *enfc_sels[]	= { "pll2_pfd0_352m", "pll2_bus", "pll3_usb_otg", "pll2_pfd2_396m", };
static const char *enfc_sels_2[]	= { "pll2_pfd0_352m", "pll2_bus", "pll3_usb_otg", "pll2_pfd2_396m", "pll3_pfd3_454m", "dummy", };
static const char *emi_sels[]		= { "pll2_pfd2_396m", "pll3_usb_otg", "axi", "pll2_pfd0_352m", };
static const char *emi_slow_sels[]      = { "axi", "pll3_usb_otg", "pll2_pfd2_396m", "pll2_pfd0_352m", };
static const char *vdo_axi_sels[]	= { "axi", "ahb", };
static const char *vpu_axi_sels[]	= { "axi", "pll2_pfd2_396m", "pll2_pfd0_352m", };
static const char *uart_sels[]	        = { "pll3_80m", "osc", };
static const char *ipg_per_sels[]	= { "ipg", "osc", };
static const char *ecspi_sels[]	= { "pll3_60m", "osc", };
static const char *can_sels[]	= { "pll3_60m", "osc", "pll3_80m", };
static const char *cko1_sels[]	= { "pll3_usb_otg", "pll2_bus", "pll1_sys", "pll5_video_div",
				    "dummy", "axi", "enfc", "ipu1_di0", "ipu1_di1", "ipu2_di0",
				    "ipu2_di1", "ahb", "ipg", "ipg_per", "ckil", "pll4_audio_div", };
static const char *cko2_sels[] = {
	"mmdc_ch0_axi", "mmdc_ch1_axi", "usdhc4", "usdhc1",
	"gpu2d_axi", "dummy", "ecspi_root", "gpu3d_axi",
	"usdhc3", "dummy", "arm", "ipu1",
	"ipu2", "vdo_axi", "osc", "gpu2d_core",
	"gpu3d_core", "usdhc2", "ssi1", "ssi2",
	"ssi3", "gpu3d_shader", "vpu_axi", "can_root",
	"ldb_di0", "ldb_di1", "esai_extal", "eim_slow",
	"uart_serial", "spdif", "asrc", "hsi_tx",
};
static const char *cko_sels[] = { "cko1", "cko2", };
static const char *lvds_sels[] = {
	"dummy", "dummy", "dummy", "dummy", "dummy", "dummy",
	"pll4_audio", "pll5_video", "pll8_mlb", "enet_ref",
	"pcie_ref_125m", "sata_ref_100m",
};
static const char *pll_bypass_src_sels[] = { "osc", "lvds1_in", "lvds2_in", "dummy", };
static const char *pll1_bypass_sels[] = { "pll1", "pll1_bypass_src", };
static const char *pll2_bypass_sels[] = { "pll2", "pll2_bypass_src", };
static const char *pll3_bypass_sels[] = { "pll3", "pll3_bypass_src", };
static const char *pll4_bypass_sels[] = { "pll4", "pll4_bypass_src", };
static const char *pll5_bypass_sels[] = { "pll5", "pll5_bypass_src", };
static const char *pll6_bypass_sels[] = { "pll6", "pll6_bypass_src", };
static const char *pll7_bypass_sels[] = { "pll7", "pll7_bypass_src", };

static struct clk *clk[IMX6QDL_CLK_END];
static struct clk_onecell_data clk_data;
static void __iomem *anatop_base;
static void __iomem *ccm_base;

static unsigned int const clks_init_on[] __initconst = {
	IMX6QDL_CLK_MMDC_CH0_AXI,
	IMX6QDL_CLK_ROM,
	IMX6QDL_CLK_ARM,
	IMX6QDL_CLK_OCRAM,
	IMX6QDL_CLK_AXI,
};

static struct clk_div_table clk_enet_ref_table[] = {
	{ .val = 0, .div = 20, },
	{ .val = 1, .div = 10, },
	{ .val = 2, .div = 5, },
	{ .val = 3, .div = 4, },
	{ /* sentinel */ }
};

static struct clk_div_table post_div_table[] = {
	{ .val = 2, .div = 1, },
	{ .val = 1, .div = 2, },
	{ .val = 0, .div = 4, },
	{ /* sentinel */ }
};

static struct clk_div_table video_div_table[] = {
	{ .val = 0, .div = 1, },
	{ .val = 1, .div = 2, },
	{ .val = 2, .div = 1, },
	{ .val = 3, .div = 4, },
	{ /* sentinel */ }
};

static unsigned int share_count_esai;
static unsigned int share_count_asrc;
static unsigned int share_count_ssi1;
static unsigned int share_count_ssi2;
static unsigned int share_count_ssi3;
static unsigned int share_count_spdif;
static unsigned int share_count_prg0;
static unsigned int share_count_prg1;

#define CCM_CCDR		0x04
#define CCM_CCSR		0x0c
#define CCM_CBCMR		0x18
#define CCM_CS2CDR		0x2c

#define CCDR_MMDC_CH1_MASK	BIT(16)
#define CCSR_PLL3_SW_CLK_SEL	BIT(0)
#define CBCMR_PRE_PERIPH_CLK_SEL_MASK	0xC0000

static int ldb_di_sel_by_clock_id(int clock_id)
{
	switch (clock_id) {
	case IMX6QDL_CLK_PLL5_VIDEO_DIV:
	if (cpu_is_imx6q() && (imx_get_soc_revision() == IMX_CHIP_REVISION_1_0))
		return -ENOENT;
	else
		return 0;
	case IMX6QDL_CLK_PLL2_PFD0_352M:
		return 1;
	case IMX6QDL_CLK_PLL2_PFD2_396M:
		return 2;
	case IMX6QDL_CLK_MMDC_CH1_AXI:
		return 3;
	case IMX6QDL_CLK_PLL3_USB_OTG:
		return 4;
	default:
		return -ENOENT;
	}
}

/*
 * Read the LDBID[0/1] parents from the device tree.
 * If no entry is found in the device tree, the default
 * parent will be set to IMX6QDL_CLK_PLL2_PFD0_352M
 */
static void of_assigned_ldb_sels(struct device_node *node,
				 int *ldb_di0_sel, int *ldb_di1_sel)
{
	struct of_phandle_args clkspec;
	int index = 0, rc;

	rc = of_parse_phandle_with_args(node, "fsl,ldb-di0-parent",
					"#clock-cells", index, &clkspec);
	if (rc < 0) {
		/* skip empty (null) phandles */
		if (rc != -ENOENT)
			*ldb_di0_sel = IMX6QDL_CLK_PLL2_PFD0_352M;
	} else {
		*ldb_di0_sel = ldb_di_sel_by_clock_id(clkspec.args[0]);
		if (*ldb_di0_sel == -ENOENT)
			*ldb_di0_sel = IMX6QDL_CLK_PLL2_PFD0_352M;
	}
	rc = of_parse_phandle_with_args(node, "fsl,ldb-di1-parent",
					"#clock-cells", index, &clkspec);
	if (rc < 0) {
		/* skip empty (null) phandles */
		if (rc != -ENOENT)
			*ldb_di1_sel = IMX6QDL_CLK_PLL2_PFD0_352M;
	} else {
		*ldb_di1_sel = ldb_di_sel_by_clock_id(clkspec.args[0]);
		if (*ldb_di1_sel == -ENOENT)
			*ldb_di1_sel = IMX6QDL_CLK_PLL2_PFD0_352M;
	}
}

static void __init mmdc_ch1_handshake(bool enable)
{
	unsigned int reg;

	if (enable) {
		reg = readl_relaxed(ccm_base + CCM_CCDR);
		reg &= ~CCDR_MMDC_CH1_MASK;
		writel_relaxed(reg, ccm_base + CCM_CCDR);
	} else {
		reg = readl_relaxed(ccm_base + CCM_CCDR);
		reg |= CCDR_MMDC_CH1_MASK;
		writel_relaxed(reg, ccm_base + CCM_CCDR);
	}
}

/*
 * The only way to disable the MMDC_CH1 clock is to move it to pll3_sw_clk
 * via periph2_clk2_sel and then to disable pll3_sw_clk by selecting the
 * bypass clock source, since there is no CG bit for mmdc_ch1.
 */
static void mmdc_ch1_disable(void)
{
	unsigned int reg;

	clk_set_parent(clk[IMX6QDL_CLK_PERIPH2_CLK2_SEL],
		       clk[IMX6QDL_CLK_PLL3_USB_OTG]);

	/*
	 * Handshake with mmdc_ch1 module must be masked when changing
	 * periph2_clk_sel.
	 */
	clk_set_parent(clk[IMX6QDL_CLK_PERIPH2], clk[IMX6QDL_CLK_PERIPH2_CLK2]);

	/* Disable pll3_sw_clk by selecting the bypass clock source */
	reg = readl_relaxed(ccm_base + CCM_CCSR);
	reg |= CCSR_PLL3_SW_CLK_SEL;
	writel_relaxed(reg, ccm_base + CCM_CCSR);
}

static void mmdc_ch1_reenable(void)
{
	unsigned int reg;

	/* Enable pll3_sw_clk by disabling the bypass */
	reg = readl_relaxed(ccm_base + CCM_CCSR);
	reg &= ~CCSR_PLL3_SW_CLK_SEL;
	writel_relaxed(reg, ccm_base + CCM_CCSR);

	clk_set_parent(clk[IMX6QDL_CLK_PERIPH2], clk[IMX6QDL_CLK_PERIPH2_PRE]);
}

/*
 * Need to follow a strict procedure when changing the LDB
 * clock, else we can introduce a glitch. Things to keep in
 * mind:
 * 1. The current and new parent clocks must be disabled.
 * 2. The default clock for ldb_dio_clk is mmdc_ch1 which has
 * no CG bit.
 * 3. In the RTL implementation of the LDB_DI_CLK_SEL mux
 * the top four options are in one mux and the PLL3 option along
 * with another option is in the second mux. There is third mux
 * used to decide between the first and second mux.
 * The code below switches the parent to the bottom mux first
 * and then manipulates the top mux. This ensures that no glitch
 * will enter the divider.
 */
static void init_ldb_clks(struct device_node *np)
{
	unsigned int reg;
	int ldb_di0_sel[4] = { 0 };
	int ldb_di1_sel[4] = { 0 };
	int i;

	reg = readl_relaxed(ccm_base + CCM_CS2CDR);
	ldb_di0_sel[0] = (reg >> 9) & 7;
	ldb_di1_sel[0] = (reg >> 12) & 7;

	of_assigned_ldb_sels(np, &ldb_di0_sel[3], &ldb_di1_sel[3]);

	if (ldb_di0_sel[0] == ldb_di0_sel[3] &&
	    ldb_di1_sel[0] == ldb_di1_sel[3])
		return;

	if (ldb_di0_sel[0] != 3 || ldb_di1_sel[0] != 3)
		pr_warn("ccm: ldb_di_sel already changed from reset value\n");

	if (ldb_di0_sel[0] > 3 || ldb_di1_sel[0] > 3 ||
	    ldb_di0_sel[3] > 3 || ldb_di1_sel[3] > 3) {
		pr_err("ccm: ldb_di_sel workaround only for top mux\n");
		return;
	}

	ldb_di0_sel[1] = ldb_di0_sel[0] | 4;	/* Ensure that lower mux is selected. */
	ldb_di0_sel[2] = ldb_di0_sel[3] | 4;	/* Change the upper mux while lower mux is selected. */
	ldb_di1_sel[1] = ldb_di1_sel[0] | 4;
	ldb_di1_sel[2] = ldb_di1_sel[3] | 4;

	mmdc_ch1_handshake(false);
	mmdc_ch1_disable();

	for (i = 1; i < 4; i++) {
		reg = readl_relaxed(ccm_base + CCM_CS2CDR);
		reg &= ~((7 << 9) | (7 << 12));
		reg |= ((ldb_di0_sel[i] << 9) | (ldb_di1_sel[i] << 12));
		writel_relaxed(reg, ccm_base + CCM_CS2CDR);
	}

	mmdc_ch1_reenable();
	mmdc_ch1_handshake(true);
}

static void disable_anatop_clocks(void)
{
	u32 reg;

	/* Make sure PFDs are disabled at boot. */
	reg = readl_relaxed(anatop_base + 0x100);
	/* Cannot gate pll2_pfd2_396m if its the parent of MMDC clock */
	if (clk_get_parent(clk[IMX6QDL_CLK_PERIPH_PRE]) ==
	    clk[IMX6QDL_CLK_PLL2_PFD2_396M])
		reg |= 0x00008080;
	else
		reg |= 0x00808080;
	writel_relaxed(reg, anatop_base + 0x100);

	/* Disable PLL3 PFDs. */
	reg = readl_relaxed(anatop_base + 0xf0);
	reg |= 0x80808080;
	writel_relaxed(reg, anatop_base + 0xf0);

	/* Make sure PLL5 (video PLL) is disabled */
	reg = readl_relaxed(anatop_base + 0xa0);
	reg &= ~(1 << 13);
	writel_relaxed(reg, anatop_base + 0xa0);
}

static void __init imx6q_clocks_init(struct device_node *ccm_node)
{
	struct device_node *np;
	void __iomem *base;
	int i;

	clk[IMX6QDL_CLK_DUMMY] = imx_clk_fixed("dummy", 0);
	clk[IMX6QDL_CLK_CKIL] = imx_obtain_fixed_clock("ckil", 0);
	clk[IMX6QDL_CLK_CKIH] = imx_obtain_fixed_clock("ckih1", 0);
	clk[IMX6QDL_CLK_OSC] = imx_obtain_fixed_clock("osc", 0);
	/* Clock source from external clock via CLK1/2 PADs */
	clk[IMX6QDL_CLK_ANACLK1] = imx_obtain_fixed_clock("anaclk1", 0);
	clk[IMX6QDL_CLK_ANACLK2] = imx_obtain_fixed_clock("anaclk2", 0);

	np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-anatop");
	base = of_iomap(np, 0);
	anatop_base = base;
	WARN_ON(!base);

	/* Audio/video PLL post dividers do not work on i.MX6q revision 1.0 */
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_1_0) {
		post_div_table[1].div = 1;
		post_div_table[2].div = 1;
		video_div_table[1].div = 1;
		video_div_table[3].div = 1;
	}

	clk[IMX6QDL_PLL1_BYPASS_SRC] = imx_clk_mux("pll1_bypass_src", base + 0x00, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL2_BYPASS_SRC] = imx_clk_mux("pll2_bypass_src", base + 0x30, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL3_BYPASS_SRC] = imx_clk_mux("pll3_bypass_src", base + 0x10, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL4_BYPASS_SRC] = imx_clk_mux("pll4_bypass_src", base + 0x70, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL5_BYPASS_SRC] = imx_clk_mux("pll5_bypass_src", base + 0xa0, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL6_BYPASS_SRC] = imx_clk_mux("pll6_bypass_src", base + 0xe0, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));
	clk[IMX6QDL_PLL7_BYPASS_SRC] = imx_clk_mux("pll7_bypass_src", base + 0x20, 14, 2, pll_bypass_src_sels, ARRAY_SIZE(pll_bypass_src_sels));

	/*                                    type               name    parent_name        base         div_mask */
	clk[IMX6QDL_CLK_PLL1] = imx_clk_pllv3(IMX_PLLV3_SYS,     "pll1", "pll1_bypass_src", base + 0x00, 0x7f);
	clk[IMX6QDL_CLK_PLL2] = imx_clk_pllv3(IMX_PLLV3_GENERIC, "pll2", "pll2_bypass_src", base + 0x30, 0x1);
	clk[IMX6QDL_CLK_PLL3] = imx_clk_pllv3(IMX_PLLV3_USB,     "pll3", "pll3_bypass_src", base + 0x10, 0x3);
	clk[IMX6QDL_CLK_PLL4] = imx_clk_pllv3(IMX_PLLV3_AV,      "pll4", "pll4_bypass_src", base + 0x70, 0x7f);
	clk[IMX6QDL_CLK_PLL5] = imx_clk_pllv3(IMX_PLLV3_AV,      "pll5", "pll5_bypass_src", base + 0xa0, 0x7f);
	clk[IMX6QDL_CLK_PLL6] = imx_clk_pllv3(IMX_PLLV3_ENET,    "pll6", "pll6_bypass_src", base + 0xe0, 0x3);
	clk[IMX6QDL_CLK_PLL7] = imx_clk_pllv3(IMX_PLLV3_USB,     "pll7", "pll7_bypass_src", base + 0x20, 0x3);

	clk[IMX6QDL_PLL1_BYPASS] = imx_clk_mux_flags("pll1_bypass", base + 0x00, 16, 1, pll1_bypass_sels, ARRAY_SIZE(pll1_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL2_BYPASS] = imx_clk_mux_flags("pll2_bypass", base + 0x30, 16, 1, pll2_bypass_sels, ARRAY_SIZE(pll2_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL3_BYPASS] = imx_clk_mux_flags("pll3_bypass", base + 0x10, 16, 1, pll3_bypass_sels, ARRAY_SIZE(pll3_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL4_BYPASS] = imx_clk_mux_flags("pll4_bypass", base + 0x70, 16, 1, pll4_bypass_sels, ARRAY_SIZE(pll4_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL5_BYPASS] = imx_clk_mux_flags("pll5_bypass", base + 0xa0, 16, 1, pll5_bypass_sels, ARRAY_SIZE(pll5_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL6_BYPASS] = imx_clk_mux_flags("pll6_bypass", base + 0xe0, 16, 1, pll6_bypass_sels, ARRAY_SIZE(pll6_bypass_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_PLL7_BYPASS] = imx_clk_mux_flags("pll7_bypass", base + 0x20, 16, 1, pll7_bypass_sels, ARRAY_SIZE(pll7_bypass_sels), CLK_SET_RATE_PARENT);

	/* Do not bypass PLLs initially */
	imx_clk_set_parent(clk[IMX6QDL_PLL1_BYPASS], clk[IMX6QDL_CLK_PLL1]);
	imx_clk_set_parent(clk[IMX6QDL_PLL2_BYPASS], clk[IMX6QDL_CLK_PLL2]);
	imx_clk_set_parent(clk[IMX6QDL_PLL3_BYPASS], clk[IMX6QDL_CLK_PLL3]);
	imx_clk_set_parent(clk[IMX6QDL_PLL4_BYPASS], clk[IMX6QDL_CLK_PLL4]);
	imx_clk_set_parent(clk[IMX6QDL_PLL5_BYPASS], clk[IMX6QDL_CLK_PLL5]);
	imx_clk_set_parent(clk[IMX6QDL_PLL6_BYPASS], clk[IMX6QDL_CLK_PLL6]);
	imx_clk_set_parent(clk[IMX6QDL_PLL7_BYPASS], clk[IMX6QDL_CLK_PLL7]);

	clk[IMX6QDL_CLK_PLL1_SYS]      = imx_clk_fixed_factor("pll1_sys",      "pll1_bypass", 1, 1);
	clk[IMX6QDL_CLK_PLL2_BUS]      = imx_clk_gate("pll2_bus",      "pll2_bypass", base + 0x30, 13);
	clk[IMX6QDL_CLK_PLL3_USB_OTG]  = imx_clk_gate("pll3_usb_otg",  "pll3_bypass", base + 0x10, 13);
	clk[IMX6QDL_CLK_PLL4_AUDIO]    = imx_clk_gate("pll4_audio",    "pll4_bypass", base + 0x70, 13);
	clk[IMX6QDL_CLK_PLL5_VIDEO]    = imx_clk_gate("pll5_video",    "pll5_bypass", base + 0xa0, 13);
	clk[IMX6QDL_CLK_PLL6_ENET]     = imx_clk_gate("pll6_enet",     "pll6_bypass", base + 0xe0, 13);
	clk[IMX6QDL_CLK_PLL7_USB_HOST] = imx_clk_gate("pll7_usb_host", "pll7_bypass", base + 0x20, 13);

	/*
	 * Bit 20 is the reserved and read-only bit, we do this only for:
	 * - Do nothing for usbphy clk_enable/disable
	 * - Keep refcount when do usbphy clk_enable/disable, in that case,
	 * the clk framework may need to enable/disable usbphy's parent
	 */
	clk[IMX6QDL_CLK_USBPHY1] = imx_clk_gate("usbphy1", "pll3_usb_otg", base + 0x10, 20);
	clk[IMX6QDL_CLK_USBPHY2] = imx_clk_gate("usbphy2", "pll7_usb_host", base + 0x20, 20);

	/*
	 * usbphy*_gate needs to be on after system boots up, and software
	 * never needs to control it anymore.
	 */
	clk[IMX6QDL_CLK_USBPHY1_GATE] = imx_clk_gate("usbphy1_gate", "dummy", base + 0x10, 6);
	clk[IMX6QDL_CLK_USBPHY2_GATE] = imx_clk_gate("usbphy2_gate", "dummy", base + 0x20, 6);

	clk[IMX6QDL_CLK_SATA_REF] = imx_clk_fixed_factor("sata_ref", "pll6_enet", 1, 5);
	clk[IMX6QDL_CLK_PCIE_REF] = imx_clk_fixed_factor("pcie_ref", "pll6_enet", 1, 4);

	clk[IMX6QDL_CLK_SATA_REF_100M] = imx_clk_gate("sata_ref_100m", "sata_ref", base + 0xe0, 20);
	clk[IMX6QDL_CLK_PCIE_REF_125M] = imx_clk_gate("pcie_ref_125m", "pcie_ref", base + 0xe0, 19);

	clk[IMX6QDL_CLK_ENET_REF] = clk_register_divider_table(NULL, "enet_ref", "pll6_enet", 0,
			base + 0xe0, 0, 2, 0, clk_enet_ref_table,
			&imx_ccm_lock);

	clk[IMX6QDL_CLK_LVDS1_SEL] = imx_clk_mux("lvds1_sel", base + 0x160, 0, 5, lvds_sels, ARRAY_SIZE(lvds_sels));
	clk[IMX6QDL_CLK_LVDS2_SEL] = imx_clk_mux("lvds2_sel", base + 0x160, 5, 5, lvds_sels, ARRAY_SIZE(lvds_sels));

	/*
	 * lvds1_gate and lvds2_gate are pseudo-gates.  Both can be
	 * independently configured as clock inputs or outputs.  We treat
	 * the "output_enable" bit as a gate, even though it's really just
	 * enabling clock output.
	 */
	clk[IMX6QDL_CLK_LVDS1_GATE] = imx_clk_gate_exclusive("lvds1_gate", "lvds1_sel", base + 0x160, 10, BIT(12));
	clk[IMX6QDL_CLK_LVDS2_GATE] = imx_clk_gate_exclusive("lvds2_gate", "lvds2_sel", base + 0x160, 11, BIT(13));

	clk[IMX6QDL_CLK_LVDS1_IN] = imx_clk_gate_exclusive("lvds1_in", "anaclk1", base + 0x160, 12, BIT(10));
	clk[IMX6QDL_CLK_LVDS2_IN] = imx_clk_gate_exclusive("lvds2_in", "anaclk2", base + 0x160, 13, BIT(11));

	/*                                            name              parent_name        reg       idx */
	clk[IMX6QDL_CLK_PLL2_PFD0_352M] = imx_clk_pfd("pll2_pfd0_352m", "pll2_bus",     base + 0x100, 0);
	clk[IMX6QDL_CLK_PLL2_PFD1_594M] = imx_clk_pfd("pll2_pfd1_594m", "pll2_bus",     base + 0x100, 1);
	clk[IMX6QDL_CLK_PLL2_PFD2_396M] = imx_clk_pfd("pll2_pfd2_396m", "pll2_bus",     base + 0x100, 2);
	clk[IMX6QDL_CLK_PLL3_PFD0_720M] = imx_clk_pfd("pll3_pfd0_720m", "pll3_usb_otg", base + 0xf0,  0);
	clk[IMX6QDL_CLK_PLL3_PFD1_540M] = imx_clk_pfd("pll3_pfd1_540m", "pll3_usb_otg", base + 0xf0,  1);
	clk[IMX6QDL_CLK_PLL3_PFD2_508M] = imx_clk_pfd("pll3_pfd2_508m", "pll3_usb_otg", base + 0xf0,  2);
	clk[IMX6QDL_CLK_PLL3_PFD3_454M] = imx_clk_pfd("pll3_pfd3_454m", "pll3_usb_otg", base + 0xf0,  3);

	/*                                                name         parent_name     mult div */
	clk[IMX6QDL_CLK_PLL2_198M] = imx_clk_fixed_factor("pll2_198m", "pll2_pfd2_396m", 1, 2);
	clk[IMX6QDL_CLK_PLL3_120M] = imx_clk_fixed_factor("pll3_120m", "pll3_usb_otg",   1, 4);
	clk[IMX6QDL_CLK_PLL3_80M]  = imx_clk_fixed_factor("pll3_80m",  "pll3_usb_otg",   1, 6);
	clk[IMX6QDL_CLK_PLL3_60M]  = imx_clk_fixed_factor("pll3_60m",  "pll3_usb_otg",   1, 8);
	clk[IMX6QDL_CLK_TWD]       = imx_clk_fixed_factor("twd",       "arm",            1, 2);
	clk[IMX6QDL_CLK_VIDEO_27M] = imx_clk_fixed_factor("video_27m", "pll3_pfd1_540m", 1, 20);
	clk[IMX6QDL_CLK_GPT_3M]    = imx_clk_fixed_factor("gpt_3m",    "osc",            1, 8);

	clk[IMX6QDL_CLK_PLL4_POST_DIV] = clk_register_divider_table(NULL, "pll4_post_div", "pll4_audio", CLK_SET_RATE_PARENT | CLK_SET_RATE_GATE, base + 0x70, 19, 2, 0, post_div_table, &imx_ccm_lock);
	clk[IMX6QDL_CLK_PLL4_AUDIO_DIV] = clk_register_divider(NULL, "pll4_audio_div", "pll4_post_div", CLK_SET_RATE_PARENT | CLK_SET_RATE_GATE, base + 0x170, 15, 1, 0, &imx_ccm_lock);
	clk[IMX6QDL_CLK_PLL5_POST_DIV] = clk_register_divider_table(NULL, "pll5_post_div", "pll5_video", CLK_SET_RATE_PARENT | CLK_SET_RATE_GATE, base + 0xa0, 19, 2, 0, post_div_table, &imx_ccm_lock);
	clk[IMX6QDL_CLK_PLL5_VIDEO_DIV] = clk_register_divider_table(NULL, "pll5_video_div", "pll5_post_div", CLK_SET_RATE_PARENT | CLK_SET_RATE_GATE, base + 0x170, 30, 2, 0, video_div_table, &imx_ccm_lock);

	np = ccm_node;
	base = of_iomap(np, 0);
	ccm_base = base;
	WARN_ON(!base);

	imx6q_pm_set_ccm_base(base);

	/*                                              name                reg       shift width parent_names     num_parents */
	clk[IMX6QDL_CLK_STEP]             = imx_clk_mux("step",	            base + 0xc,  8,  1, step_sels,	   ARRAY_SIZE(step_sels));
	clk[IMX6QDL_CLK_PLL1_SW]          = imx_clk_mux_glitchless("pll1_sw", base + 0xc, 2, 1, pll1_sw_sels,      ARRAY_SIZE(pll1_sw_sels));
	clk[IMX6QDL_CLK_PERIPH_PRE]       = imx_clk_mux_bus("periph_pre",       base + 0x18, 18, 2, periph_pre_sels,   ARRAY_SIZE(periph_pre_sels));
	clk[IMX6QDL_CLK_PERIPH2_PRE]      = imx_clk_mux("periph2_pre",      base + 0x18, 21, 2, periph_pre_sels,   ARRAY_SIZE(periph_pre_sels));
	clk[IMX6QDL_CLK_PERIPH_CLK2_SEL]  = imx_clk_mux_bus("periph_clk2_sel",  base + 0x18, 12, 2, periph_clk2_sels,  ARRAY_SIZE(periph_clk2_sels));
	clk[IMX6QDL_CLK_PERIPH2_CLK2_SEL] = imx_clk_mux("periph2_clk2_sel", base + 0x18, 20, 1, periph2_clk2_sels, ARRAY_SIZE(periph2_clk2_sels));
	clk[IMX6QDL_CLK_AXI_ALT_SEL]      = imx_clk_mux("axi_alt_sel",      base + 0x14, 7,  1, axi_alt_sels,      ARRAY_SIZE(axi_alt_sels));
	clk[IMX6QDL_CLK_AXI_SEL]          = imx_clk_mux_glitchless("axi_sel", base + 0x14, 6, 1, axi_sels,         ARRAY_SIZE(axi_sels));
	clk[IMX6QDL_CLK_ESAI_SEL]         = imx_clk_mux("esai_sel",         base + 0x20, 19, 2, audio_sels,        ARRAY_SIZE(audio_sels));
	clk[IMX6QDL_CLK_ASRC_SEL]         = imx_clk_mux("asrc_sel",         base + 0x30, 7,  2, audio_sels,        ARRAY_SIZE(audio_sels));
	clk[IMX6QDL_CLK_SPDIF_SEL]        = imx_clk_mux("spdif_sel",        base + 0x30, 20, 2, audio_sels,        ARRAY_SIZE(audio_sels));

	/*                                                        name                 parent_name    reg        shift width busy: reg, shift */
	clk[IMX6QDL_CLK_AXI]               = imx_clk_busy_divider("axi",               "axi_sel",     base + 0x14, 16,  3,   base + 0x48, 0);
	clk[IMX6QDL_CLK_MMDC_CH0_AXI]      = imx_clk_busy_divider("mmdc_ch0_axi",      "periph",      base + 0x14, 19,  3,   base + 0x48, 4);
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_MMDC_CH1_AXI_CG] = imx_clk_gate("mmdc_ch1_axi_cg", "periph2", base + 0x4, 18);
		clk[IMX6QDL_CLK_MMDC_CH1_AXI]      = imx_clk_busy_divider("mmdc_ch1_axi",      "mmdc_ch1_axi_cg",     base + 0x14, 3,   3,   base + 0x48, 2);
	} else {
		clk[IMX6QDL_CLK_MMDC_CH1_AXI]      = imx_clk_busy_divider("mmdc_ch1_axi",      "periph2",     base + 0x14, 3,   3,   base + 0x48, 2);
	}
	clk[IMX6QDL_CLK_ARM]               = imx_clk_busy_divider("arm",               "pll1_sw",     base + 0x10, 0,   3,   base + 0x48, 16);
	clk[IMX6QDL_CLK_AHB]               = imx_clk_busy_divider("ahb",               "periph",      base + 0x14, 10,  3,   base + 0x48, 1);

	/*                                                  name                parent_name          reg       shift width */
	clk[IMX6QDL_CLK_PERIPH_CLK2]      = imx_clk_divider("periph_clk2",      "periph_clk2_sel",   base + 0x14, 27, 3);
	clk[IMX6QDL_CLK_PERIPH2_CLK2]     = imx_clk_divider("periph2_clk2",     "periph2_clk2_sel",  base + 0x14, 0,  3);
	clk[IMX6QDL_CLK_IPG]              = imx_clk_divider("ipg",              "ahb",               base + 0x14, 8,  2);

	/*                                          name         reg      shift width busy: reg, shift parent_names  num_parents */
	clk[IMX6QDL_CLK_PERIPH]  = imx_clk_busy_mux("periph",  base + 0x14, 25,  1,   base + 0x48, 5,  periph_sels,  ARRAY_SIZE(periph_sels));
	clk[IMX6QDL_CLK_PERIPH2] = imx_clk_busy_mux("periph2", base + 0x14, 26,  1,   base + 0x48, 3,  periph2_sels, ARRAY_SIZE(periph2_sels));

	if ((cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) || cpu_is_imx6dl()) {
		clk[IMX6QDL_CLK_GPU2D_AXI] = imx_clk_fixed_factor("gpu2d_axi", "mmdc_ch0_axi", 1, 1);
		clk[IMX6QDL_CLK_GPU3D_AXI] = imx_clk_fixed_factor("gpu3d_axi", "mmdc_ch0_axi", 1, 1);
	} else {
		clk[IMX6QDL_CLK_GPU2D_AXI]        = imx_clk_mux("gpu2d_axi",        base + 0x18, 0,  1, gpu_axi_sels,      ARRAY_SIZE(gpu_axi_sels));
		clk[IMX6QDL_CLK_GPU3D_AXI]        = imx_clk_mux("gpu3d_axi",        base + 0x18, 1,  1, gpu_axi_sels,      ARRAY_SIZE(gpu_axi_sels));
	}

	clk[IMX6QDL_CLK_GPU3D_CORE_SEL]   = imx_clk_mux("gpu3d_core_sel",   base + 0x18, 4,  2, gpu3d_core_sels,   ARRAY_SIZE(gpu3d_core_sels));
	clk[IMX6QDL_CLK_GPU3D_SHADER_SEL] = imx_clk_mux("gpu3d_shader_sel", base + 0x18, 8,  2, gpu3d_shader_sels, ARRAY_SIZE(gpu3d_shader_sels));
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_CAN_SEL] = imx_clk_mux("can_sel", base + 0x20, 8,  2, can_sels, ARRAY_SIZE(can_sels));
		clk[IMX6QDL_CLK_ECSPI_SEL] = imx_clk_mux("ecspi_sel", base + 0x38, 18,  1, ecspi_sels, ARRAY_SIZE(ecspi_sels));
		clk[IMX6QDL_CLK_IPG_PER_SEL] = imx_clk_mux("ipg_per_sel", base + 0x1c, 6,  1, ipg_per_sels, ARRAY_SIZE(ipg_per_sels));
		clk[IMX6QDL_CLK_UART_SEL] = imx_clk_mux("uart_sel", base + 0x24, 6,  1, uart_sels, ARRAY_SIZE(uart_sels));
		clk[IMX6QDL_CLK_GPU2D_CORE_SEL]   = imx_clk_mux("gpu2d_core_sel",   base + 0x18, 16, 2, gpu2d_core_sels_2,   ARRAY_SIZE(gpu2d_core_sels_2));
	} else {
		clk[IMX6QDL_CLK_GPU2D_CORE_SEL]   = imx_clk_mux("gpu2d_core_sel",   base + 0x18, 16, 2, gpu2d_core_sels,   ARRAY_SIZE(gpu2d_core_sels));
	}
	clk[IMX6QDL_CLK_IPU1_SEL]         = imx_clk_mux("ipu1_sel",         base + 0x3c, 9,  2, ipu_sels,          ARRAY_SIZE(ipu_sels));
	clk[IMX6QDL_CLK_IPU2_SEL]         = imx_clk_mux("ipu2_sel",         base + 0x3c, 14, 2, ipu_sels,          ARRAY_SIZE(ipu_sels));
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_LDB_DI0_SEL]      = imx_clk_mux_flags("ldb_di0_sel", base + 0x2c, 9,  3, ldb_di_sels,      ARRAY_SIZE(ldb_di_sels), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_LDB_DI1_SEL]      = imx_clk_mux_flags("ldb_di1_sel", base + 0x2c, 12, 3, ldb_di_sels,      ARRAY_SIZE(ldb_di_sels), CLK_SET_RATE_PARENT);
	} else {
		/*
		 * The LDB_DI0/1_SEL muxes are registered read-only due to a hardware
		 * bug. Set the muxes to the requested values before registering the
		 * ldb_di_sel clocks.
		 */
		disable_anatop_clocks();
		init_ldb_clks(np);
		clk[IMX6QDL_CLK_LDB_DI0_SEL]      = imx_clk_mux_ldb("ldb_di0_sel", base + 0x2c, 9,  3, ldb_di_sels,      ARRAY_SIZE(ldb_di_sels));
		clk[IMX6QDL_CLK_LDB_DI1_SEL]      = imx_clk_mux_ldb("ldb_di1_sel", base + 0x2c, 12, 3, ldb_di_sels,      ARRAY_SIZE(ldb_di_sels));
	}
	clk[IMX6QDL_CLK_LDB_DI0_DIV_SEL]  = imx_clk_mux_flags("ldb_di0_div_sel", base + 0x20, 10, 1, ldb_di0_div_sels, ARRAY_SIZE(ldb_di0_div_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_CLK_LDB_DI1_DIV_SEL]  = imx_clk_mux_flags("ldb_di1_div_sel", base + 0x20, 11, 1, ldb_di1_div_sels, ARRAY_SIZE(ldb_di1_div_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_CLK_IPU1_DI0_PRE_SEL] = imx_clk_mux_flags("ipu1_di0_pre_sel", base + 0x34, 6,  3, ipu_di_pre_sels,   ARRAY_SIZE(ipu_di_pre_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_CLK_IPU1_DI1_PRE_SEL] = imx_clk_mux_flags("ipu1_di1_pre_sel", base + 0x34, 15, 3, ipu_di_pre_sels,   ARRAY_SIZE(ipu_di_pre_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_CLK_IPU2_DI0_PRE_SEL] = imx_clk_mux_flags("ipu2_di0_pre_sel", base + 0x38, 6,  3, ipu_di_pre_sels,   ARRAY_SIZE(ipu_di_pre_sels), CLK_SET_RATE_PARENT);
	clk[IMX6QDL_CLK_IPU2_DI1_PRE_SEL] = imx_clk_mux_flags("ipu2_di1_pre_sel", base + 0x38, 15, 3, ipu_di_pre_sels,   ARRAY_SIZE(ipu_di_pre_sels), CLK_SET_RATE_PARENT);

	clk[IMX6QDL_CLK_HSI_TX_SEL]       = imx_clk_mux("hsi_tx_sel",       base + 0x30, 28, 1, hsi_tx_sels,       ARRAY_SIZE(hsi_tx_sels));
	clk[IMX6QDL_CLK_PCIE_AXI_SEL]     = imx_clk_mux("pcie_axi_sel",     base + 0x18, 10, 1, pcie_axi_sels,     ARRAY_SIZE(pcie_axi_sels));
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_IPU1_DI0_SEL]     = imx_clk_mux_flags("ipu1_di0_sel",     base + 0x34, 0,  3, ipu1_di0_sels_2,     ARRAY_SIZE(ipu1_di0_sels_2), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU1_DI1_SEL]     = imx_clk_mux_flags("ipu1_di1_sel",     base + 0x34, 9,  3, ipu1_di1_sels_2,     ARRAY_SIZE(ipu1_di1_sels_2), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU2_DI0_SEL]     = imx_clk_mux_flags("ipu2_di0_sel",     base + 0x38, 0,  3, ipu2_di0_sels_2,     ARRAY_SIZE(ipu2_di0_sels_2), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU2_DI1_SEL]     = imx_clk_mux_flags("ipu2_di1_sel",     base + 0x38, 9,  3, ipu2_di1_sels_2,     ARRAY_SIZE(ipu2_di1_sels_2), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_SSI1_SEL]         = imx_clk_mux("ssi1_sel",   base + 0x1c, 10, 2, ssi_sels,          ARRAY_SIZE(ssi_sels));
		clk[IMX6QDL_CLK_SSI2_SEL]         = imx_clk_mux("ssi2_sel",   base + 0x1c, 12, 2, ssi_sels,          ARRAY_SIZE(ssi_sels));
		clk[IMX6QDL_CLK_SSI3_SEL]         = imx_clk_mux("ssi3_sel",   base + 0x1c, 14, 2, ssi_sels,          ARRAY_SIZE(ssi_sels));
		clk[IMX6QDL_CLK_USDHC1_SEL]       = imx_clk_mux("usdhc1_sel", base + 0x1c, 16, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels));
		clk[IMX6QDL_CLK_USDHC2_SEL]       = imx_clk_mux("usdhc2_sel", base + 0x1c, 17, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels));
		clk[IMX6QDL_CLK_USDHC3_SEL]       = imx_clk_mux("usdhc3_sel", base + 0x1c, 18, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels));
		clk[IMX6QDL_CLK_USDHC4_SEL]       = imx_clk_mux("usdhc4_sel", base + 0x1c, 19, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels));
		clk[IMX6QDL_CLK_ENFC_SEL]         = imx_clk_mux("enfc_sel",         base + 0x2c, 15, 3, enfc_sels_2,         ARRAY_SIZE(enfc_sels_2));
		clk[IMX6QDL_CLK_EMI_SEL]          = imx_clk_mux("emi_sel",      base + 0x1c, 27, 2, emi_sels,        ARRAY_SIZE(emi_sels));
		clk[IMX6QDL_CLK_EMI_SLOW_SEL]     = imx_clk_mux("emi_slow_sel", base + 0x1c, 29, 2, emi_slow_sels,   ARRAY_SIZE(emi_slow_sels));
		clk[IMX6QDL_CLK_PRE_AXI]	  = imx_clk_mux("pre_axi",	base + 0x18, 1, 1, pre_axi_sels,     ARRAY_SIZE(pre_axi_sels));
	} else {
		clk[IMX6QDL_CLK_IPU1_DI0_SEL]     = imx_clk_mux_flags("ipu1_di0_sel",     base + 0x34, 0,  3, ipu1_di0_sels,     ARRAY_SIZE(ipu1_di0_sels), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU1_DI1_SEL]     = imx_clk_mux_flags("ipu1_di1_sel",     base + 0x34, 9,  3, ipu1_di1_sels,     ARRAY_SIZE(ipu1_di1_sels), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU2_DI0_SEL]     = imx_clk_mux_flags("ipu2_di0_sel",     base + 0x38, 0,  3, ipu2_di0_sels,     ARRAY_SIZE(ipu2_di0_sels), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_IPU2_DI1_SEL]     = imx_clk_mux_flags("ipu2_di1_sel",     base + 0x38, 9,  3, ipu2_di1_sels,     ARRAY_SIZE(ipu2_di1_sels), CLK_SET_RATE_PARENT);
		clk[IMX6QDL_CLK_SSI1_SEL]         = imx_clk_fixup_mux("ssi1_sel",   base + 0x1c, 10, 2, ssi_sels,          ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_SSI2_SEL]         = imx_clk_fixup_mux("ssi2_sel",   base + 0x1c, 12, 2, ssi_sels,          ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_SSI3_SEL]         = imx_clk_fixup_mux("ssi3_sel",   base + 0x1c, 14, 2, ssi_sels,          ARRAY_SIZE(ssi_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_USDHC1_SEL]       = imx_clk_fixup_mux("usdhc1_sel", base + 0x1c, 16, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_USDHC2_SEL]       = imx_clk_fixup_mux("usdhc2_sel", base + 0x1c, 17, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_USDHC3_SEL]       = imx_clk_fixup_mux("usdhc3_sel", base + 0x1c, 18, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_USDHC4_SEL]       = imx_clk_fixup_mux("usdhc4_sel", base + 0x1c, 19, 1, usdhc_sels,        ARRAY_SIZE(usdhc_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_ENFC_SEL]         = imx_clk_mux("enfc_sel",         base + 0x2c, 16, 2, enfc_sels,         ARRAY_SIZE(enfc_sels));
		clk[IMX6QDL_CLK_EMI_SEL]          = imx_clk_fixup_mux("emi_sel",      base + 0x1c, 27, 2, emi_sels,        ARRAY_SIZE(emi_sels), imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_EMI_SLOW_SEL]     = imx_clk_fixup_mux("emi_slow_sel", base + 0x1c, 29, 2, emi_slow_sels,   ARRAY_SIZE(emi_slow_sels), imx_cscmr1_fixup);
	}
	clk[IMX6QDL_CLK_VDO_AXI_SEL]      = imx_clk_mux("vdo_axi_sel",      base + 0x18, 11, 1, vdo_axi_sels,      ARRAY_SIZE(vdo_axi_sels));
	clk[IMX6QDL_CLK_VPU_AXI_SEL]      = imx_clk_mux("vpu_axi_sel",      base + 0x18, 14, 2, vpu_axi_sels,      ARRAY_SIZE(vpu_axi_sels));
	clk[IMX6QDL_CLK_CKO1_SEL]         = imx_clk_mux("cko1_sel",         base + 0x60, 0,  4, cko1_sels,         ARRAY_SIZE(cko1_sels));
	clk[IMX6QDL_CLK_CKO2_SEL]         = imx_clk_mux("cko2_sel",         base + 0x60, 16, 5, cko2_sels,         ARRAY_SIZE(cko2_sels));
	clk[IMX6QDL_CLK_CKO]              = imx_clk_mux("cko",              base + 0x60, 8, 1,  cko_sels,          ARRAY_SIZE(cko_sels));

	/*                                                  name                parent_name          reg       shift width */
	clk[IMX6QDL_CLK_ESAI_PRED]        = imx_clk_divider("esai_pred",        "esai_sel",          base + 0x28, 9,  3);
	clk[IMX6QDL_CLK_ESAI_PODF]        = imx_clk_divider("esai_podf",        "esai_pred",         base + 0x28, 25, 3);
	clk[IMX6QDL_CLK_ASRC_PRED]        = imx_clk_divider("asrc_pred",        "asrc_sel",          base + 0x30, 12, 3);
	clk[IMX6QDL_CLK_ASRC_PODF]        = imx_clk_divider("asrc_podf",        "asrc_pred",         base + 0x30, 9,  3);
	clk[IMX6QDL_CLK_SPDIF_PRED]       = imx_clk_divider("spdif_pred",       "spdif_sel",         base + 0x30, 25, 3);
	clk[IMX6QDL_CLK_SPDIF_PODF]       = imx_clk_divider("spdif_podf",       "spdif_pred",        base + 0x30, 22, 3);
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_IPG_PER]          = imx_clk_divider("ipg_per",    "ipg_per_sel",       base + 0x1c, 0,  6);
		clk[IMX6QDL_CLK_ECSPI_ROOT]       = imx_clk_divider("ecspi_root",       "ecspi_sel",          base + 0x38, 19, 6);
		clk[IMX6QDL_CLK_CAN_ROOT]         = imx_clk_divider("can_root",         "can_sel",          base + 0x20, 2,  6);
		clk[IMX6QDL_CLK_UART_SERIAL_PODF] = imx_clk_divider("uart_serial_podf", "uart_sel",          base + 0x24, 0,  6);
		clk[IMX6QDL_CLK_LDB_DI0_DIV_3_5]  = imx_clk_fixed_factor("ldb_di0_div_3_5", "ldb_di0", 2, 7);
		clk[IMX6QDL_CLK_LDB_DI0_DIV_7]    = imx_clk_fixed_factor("ldb_di0_div_7",   "ldb_di0", 1, 7);
		clk[IMX6QDL_CLK_LDB_DI1_DIV_3_5]  = imx_clk_fixed_factor("ldb_di1_div_3_5", "ldb_di1", 2, 7);
		clk[IMX6QDL_CLK_LDB_DI1_DIV_7]    = imx_clk_fixed_factor("ldb_di1_div_7",   "ldb_di1", 1, 7);
	} else {
		clk[IMX6QDL_CLK_ECSPI_ROOT]       = imx_clk_divider("ecspi_root",       "pll3_60m",          base + 0x38, 19, 6);
		clk[IMX6QDL_CLK_CAN_ROOT]         = imx_clk_divider("can_root",         "pll3_60m",          base + 0x20, 2,  6);
		clk[IMX6QDL_CLK_IPG_PER]          = imx_clk_fixup_divider("ipg_per",    "ipg",       base + 0x1c, 0,  6, imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_UART_SERIAL_PODF] = imx_clk_divider("uart_serial_podf", "pll3_80m",          base + 0x24, 0,  6);
		clk[IMX6QDL_CLK_LDB_DI0_DIV_3_5]  = imx_clk_fixed_factor("ldb_di0_div_3_5", "ldb_di0_sel", 2, 7);
		clk[IMX6QDL_CLK_LDB_DI0_DIV_7]    = imx_clk_fixed_factor("ldb_di0_div_7",   "ldb_di0_sel", 1, 7);
		clk[IMX6QDL_CLK_LDB_DI1_DIV_3_5]  = imx_clk_fixed_factor("ldb_di1_div_3_5", "ldb_di1_sel", 2, 7);
		clk[IMX6QDL_CLK_LDB_DI1_DIV_7]    = imx_clk_fixed_factor("ldb_di1_div_7",   "ldb_di1_sel", 1, 7);
	}
	clk[IMX6QDL_CLK_GPU2D_CORE_PODF]  = imx_clk_divider("gpu2d_core_podf",  "gpu2d_core_sel",    base + 0x18, 23, 3);
	clk[IMX6QDL_CLK_GPU3D_CORE_PODF]  = imx_clk_divider("gpu3d_core_podf",  "gpu3d_core_sel",    base + 0x18, 26, 3);
	clk[IMX6QDL_CLK_GPU3D_SHADER]     = imx_clk_divider("gpu3d_shader",     "gpu3d_shader_sel",  base + 0x18, 29, 3);
	clk[IMX6QDL_CLK_IPU1_PODF]        = imx_clk_divider("ipu1_podf",        "ipu1_sel",          base + 0x3c, 11, 3);
	clk[IMX6QDL_CLK_IPU2_PODF]        = imx_clk_divider("ipu2_podf",        "ipu2_sel",          base + 0x3c, 16, 3);
	clk[IMX6QDL_CLK_IPU1_DI0_PRE]     = imx_clk_divider("ipu1_di0_pre",     "ipu1_di0_pre_sel",  base + 0x34, 3,  3);
	clk[IMX6QDL_CLK_IPU1_DI1_PRE]     = imx_clk_divider("ipu1_di1_pre",     "ipu1_di1_pre_sel",  base + 0x34, 12, 3);
	clk[IMX6QDL_CLK_IPU2_DI0_PRE]     = imx_clk_divider("ipu2_di0_pre",     "ipu2_di0_pre_sel",  base + 0x38, 3,  3);
	clk[IMX6QDL_CLK_IPU2_DI1_PRE]     = imx_clk_divider("ipu2_di1_pre",     "ipu2_di1_pre_sel",  base + 0x38, 12, 3);
	clk[IMX6QDL_CLK_HSI_TX_PODF]      = imx_clk_divider("hsi_tx_podf",      "hsi_tx_sel",        base + 0x30, 29, 3);
	clk[IMX6QDL_CLK_SSI1_PRED]        = imx_clk_divider("ssi1_pred",        "ssi1_sel",          base + 0x28, 6,  3);
	clk[IMX6QDL_CLK_SSI1_PODF]        = imx_clk_divider("ssi1_podf",        "ssi1_pred",         base + 0x28, 0,  6);
	clk[IMX6QDL_CLK_SSI2_PRED]        = imx_clk_divider("ssi2_pred",        "ssi2_sel",          base + 0x2c, 6,  3);
	clk[IMX6QDL_CLK_SSI2_PODF]        = imx_clk_divider("ssi2_podf",        "ssi2_pred",         base + 0x2c, 0,  6);
	clk[IMX6QDL_CLK_SSI3_PRED]        = imx_clk_divider("ssi3_pred",        "ssi3_sel",          base + 0x28, 22, 3);
	clk[IMX6QDL_CLK_SSI3_PODF]        = imx_clk_divider("ssi3_podf",        "ssi3_pred",         base + 0x28, 16, 6);
	clk[IMX6QDL_CLK_USDHC1_PODF]      = imx_clk_divider("usdhc1_podf",      "usdhc1_sel",        base + 0x24, 11, 3);
	clk[IMX6QDL_CLK_USDHC2_PODF]      = imx_clk_divider("usdhc2_podf",      "usdhc2_sel",        base + 0x24, 16, 3);
	clk[IMX6QDL_CLK_USDHC3_PODF]      = imx_clk_divider("usdhc3_podf",      "usdhc3_sel",        base + 0x24, 19, 3);
	clk[IMX6QDL_CLK_USDHC4_PODF]      = imx_clk_divider("usdhc4_podf",      "usdhc4_sel",        base + 0x24, 22, 3);
	clk[IMX6QDL_CLK_ENFC_PRED]        = imx_clk_divider("enfc_pred",        "enfc_sel",          base + 0x2c, 18, 3);
	clk[IMX6QDL_CLK_ENFC_PODF]        = imx_clk_divider("enfc_podf",        "enfc_pred",         base + 0x2c, 21, 6);
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_EMI_PODF]         = imx_clk_divider("emi_podf",   "emi_sel",           base + 0x1c, 20, 3);
		clk[IMX6QDL_CLK_EMI_SLOW_PODF]    = imx_clk_divider("emi_slow_podf", "emi_slow_sel",   base + 0x1c, 23, 3);
	} else {
		clk[IMX6QDL_CLK_EMI_PODF]         = imx_clk_fixup_divider("emi_podf",   "emi_sel",           base + 0x1c, 20, 3, imx_cscmr1_fixup);
		clk[IMX6QDL_CLK_EMI_SLOW_PODF]    = imx_clk_fixup_divider("emi_slow_podf", "emi_slow_sel",   base + 0x1c, 23, 3, imx_cscmr1_fixup);
	}
	clk[IMX6QDL_CLK_VPU_AXI_PODF]     = imx_clk_divider("vpu_axi_podf",     "vpu_axi_sel",       base + 0x24, 25, 3);
	clk[IMX6QDL_CLK_CKO1_PODF]        = imx_clk_divider("cko1_podf",        "cko1_sel",          base + 0x60, 4,  3);
	clk[IMX6QDL_CLK_CKO2_PODF]        = imx_clk_divider("cko2_podf",        "cko2_sel",          base + 0x60, 21, 3);

	/*                                            name             parent_name          reg         shift */
	clk[IMX6QDL_CLK_APBH_DMA]     = imx_clk_gate2("apbh_dma",      "usdhc3",            base + 0x68, 4);
	clk[IMX6QDL_CLK_ASRC]         = imx_clk_gate2_shared("asrc",         "asrc_podf",   base + 0x68, 6, &share_count_asrc);
	clk[IMX6QDL_CLK_ASRC_IPG]     = imx_clk_gate2_shared("asrc_ipg",     "ahb",         base + 0x68, 6, &share_count_asrc);
	clk[IMX6QDL_CLK_ASRC_MEM]     = imx_clk_gate2_shared("asrc_mem",     "ahb",         base + 0x68, 6, &share_count_asrc);
	clk[IMX6QDL_CAAM_MEM]         = imx_clk_gate2("caam_mem",      "ahb",               base + 0x68, 8);
	clk[IMX6QDL_CAAM_ACLK]        = imx_clk_gate2("caam_aclk",     "ahb",               base + 0x68, 10);
	clk[IMX6QDL_CAAM_IPG]         = imx_clk_gate2("caam_ipg",      "ipg",               base + 0x68, 12);
	clk[IMX6QDL_CLK_CAN1_IPG]     = imx_clk_gate2("can1_ipg",      "ipg",               base + 0x68, 14);
	clk[IMX6QDL_CLK_CAN1_SERIAL]  = imx_clk_gate2("can1_serial",   "can_root",          base + 0x68, 16);
	clk[IMX6QDL_CLK_CAN2_IPG]     = imx_clk_gate2("can2_ipg",      "ipg",               base + 0x68, 18);
	clk[IMX6QDL_CLK_CAN2_SERIAL]  = imx_clk_gate2("can2_serial",   "can_root",          base + 0x68, 20);
	clk[IMX6QDL_CLK_DCIC1]        = imx_clk_gate2("dcic1",         "ipu1_podf",         base + 0x68, 24);
	clk[IMX6QDL_CLK_DCIC2]        = imx_clk_gate2("dcic2",         "ipu2_podf",         base + 0x68, 26);
	clk[IMX6QDL_CLK_ECSPI1]       = imx_clk_gate2("ecspi1",        "ecspi_root",        base + 0x6c, 0);
	clk[IMX6QDL_CLK_ECSPI2]       = imx_clk_gate2("ecspi2",        "ecspi_root",        base + 0x6c, 2);
	clk[IMX6QDL_CLK_ECSPI3]       = imx_clk_gate2("ecspi3",        "ecspi_root",        base + 0x6c, 4);
	clk[IMX6QDL_CLK_ECSPI4]       = imx_clk_gate2("ecspi4",        "ecspi_root",        base + 0x6c, 6);
	if (cpu_is_imx6dl())
		clk[IMX6DL_CLK_I2C4]  = imx_clk_gate2("i2c4",          "ipg_per",           base + 0x6c, 8);
	else
		clk[IMX6Q_CLK_ECSPI5] = imx_clk_gate2("ecspi5",        "ecspi_root",        base + 0x6c, 8);
	clk[IMX6QDL_CLK_ENET]         = imx_clk_gate2("enet",          "ipg",               base + 0x6c, 10);
	clk[IMX6QDL_CLK_ESAI_EXTAL]   = imx_clk_gate2_shared("esai_extal",   "esai_podf",   base + 0x6c, 16, &share_count_esai);
	clk[IMX6QDL_CLK_ESAI_IPG]     = imx_clk_gate2_shared("esai_ipg",   "ahb",           base + 0x6c, 16, &share_count_esai);
	clk[IMX6QDL_CLK_ESAI_MEM]     = imx_clk_gate2_shared("esai_mem", "ahb",             base + 0x6c, 16, &share_count_esai);
	clk[IMX6QDL_CLK_GPT_IPG]      = imx_clk_gate2("gpt_ipg",       "ipg",               base + 0x6c, 20);
	clk[IMX6QDL_CLK_GPT_IPG_PER]  = imx_clk_gate2("gpt_ipg_per",   "ipg_per",           base + 0x6c, 22);
	if (cpu_is_imx6dl())
		/*
		 * The multiplexer and divider of imx6q clock gpu3d_shader get
		 * redefined/reused as gpu2d_core_sel and gpu2d_core_podf on imx6dl.
		 */
		clk[IMX6QDL_CLK_GPU2D_CORE] = imx_clk_gate2("gpu2d_core", "gpu3d_shader", base + 0x6c, 24);
	else
		clk[IMX6QDL_CLK_GPU2D_CORE] = imx_clk_gate2("gpu2d_core", "gpu2d_core_podf", base + 0x6c, 24);
	clk[IMX6QDL_CLK_GPU3D_CORE]   = imx_clk_gate2("gpu3d_core",    "gpu3d_core_podf",   base + 0x6c, 26);
	clk[IMX6QDL_CLK_HDMI_IAHB]    = imx_clk_gate2("hdmi_iahb",     "ahb",               base + 0x70, 0);
	clk[IMX6QDL_CLK_HDMI_ISFR]    = imx_clk_gate2("hdmi_isfr",     "pll3_pfd1_540m",    base + 0x70, 4);
	clk[IMX6QDL_CLK_I2C1]         = imx_clk_gate2("i2c1",          "ipg_per",           base + 0x70, 6);
	clk[IMX6QDL_CLK_I2C2]         = imx_clk_gate2("i2c2",          "ipg_per",           base + 0x70, 8);
	clk[IMX6QDL_CLK_I2C3]         = imx_clk_gate2("i2c3",          "ipg_per",           base + 0x70, 10);
	clk[IMX6QDL_CLK_IIM]          = imx_clk_gate2("iim",           "ipg",               base + 0x70, 12);
	clk[IMX6QDL_CLK_ENFC]         = imx_clk_gate2("enfc",          "enfc_podf",         base + 0x70, 14);
	clk[IMX6QDL_CLK_VDOA]         = imx_clk_gate2("vdoa",          "vdo_axi",           base + 0x70, 26);
	clk[IMX6QDL_CLK_IPU1]         = imx_clk_gate2("ipu1",          "ipu1_podf",         base + 0x74, 0);
	clk[IMX6QDL_CLK_IPU1_DI0]     = imx_clk_gate2("ipu1_di0",      "ipu1_di0_sel",      base + 0x74, 2);
	clk[IMX6QDL_CLK_IPU1_DI1]     = imx_clk_gate2("ipu1_di1",      "ipu1_di1_sel",      base + 0x74, 4);
	clk[IMX6QDL_CLK_IPU2]         = imx_clk_gate2("ipu2",          "ipu2_podf",         base + 0x74, 6);
	clk[IMX6QDL_CLK_IPU2_DI0]     = imx_clk_gate2("ipu2_di0",      "ipu2_di0_sel",      base + 0x74, 8);

	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_LDB_DI0]      = imx_clk_gate2("ldb_di0",       "ldb_di0_sel",   base + 0x74, 12);
		clk[IMX6QDL_CLK_LDB_DI1]      = imx_clk_gate2("ldb_di1",       "ldb_di1_sel",   base + 0x74, 14);
	} else {
		clk[IMX6QDL_CLK_LDB_DI0]      = imx_clk_gate2("ldb_di0",       "ldb_di0_div_sel",   base + 0x74, 12);
		clk[IMX6QDL_CLK_LDB_DI1]      = imx_clk_gate2("ldb_di1",       "ldb_di1_div_sel",   base + 0x74, 14);
	}
	clk[IMX6QDL_CLK_IPU2_DI1]     = imx_clk_gate2("ipu2_di1",      "ipu2_di1_sel",      base + 0x74, 10);
	clk[IMX6QDL_CLK_HSI_TX]       = imx_clk_gate2("hsi_tx",        "hsi_tx_podf",       base + 0x74, 16);
	if (cpu_is_imx6dl())
		/*
		 * The multiplexer and divider of the imx6q clock gpu2d get
		 * redefined/reused as mlb_sys_sel and mlb_sys_clk_podf on imx6dl.
		 */
		clk[IMX6QDL_CLK_MLB] = imx_clk_gate2("mlb",            "gpu2d_core_podf",   base + 0x74, 18);
	else
		clk[IMX6QDL_CLK_MLB] = imx_clk_gate2("mlb",            "axi",               base + 0x74, 18);
	clk[IMX6QDL_CLK_OCRAM]        = imx_clk_gate2("ocram",         "ahb",               base + 0x74, 28);
	clk[IMX6QDL_CLK_OPENVG_AXI]   = imx_clk_gate2("openvg_axi",    "axi",               base + 0x74, 30);
	clk[IMX6QDL_CLK_PCIE_AXI]     = imx_clk_gate2("pcie_axi",      "pcie_axi_sel",      base + 0x78, 0);
	clk[IMX6QDL_CLK_PER1_BCH]     = imx_clk_gate2("per1_bch",      "usdhc3",            base + 0x78, 12);
	clk[IMX6QDL_CLK_PWM1]         = imx_clk_gate2("pwm1",          "ipg_per",           base + 0x78, 16);
	clk[IMX6QDL_CLK_PWM2]         = imx_clk_gate2("pwm2",          "ipg_per",           base + 0x78, 18);
	clk[IMX6QDL_CLK_PWM3]         = imx_clk_gate2("pwm3",          "ipg_per",           base + 0x78, 20);
	clk[IMX6QDL_CLK_PWM4]         = imx_clk_gate2("pwm4",          "ipg_per",           base + 0x78, 22);
	clk[IMX6QDL_CLK_GPMI_BCH_APB] = imx_clk_gate2("gpmi_bch_apb",  "usdhc3",            base + 0x78, 24);
	clk[IMX6QDL_CLK_GPMI_BCH]     = imx_clk_gate2("gpmi_bch",      "usdhc4",            base + 0x78, 26);
	clk[IMX6QDL_CLK_GPMI_IO]      = imx_clk_gate2("gpmi_io",       "enfc",              base + 0x78, 28);
	clk[IMX6QDL_CLK_GPMI_APB]     = imx_clk_gate2("gpmi_apb",      "usdhc3",            base + 0x78, 30);
	clk[IMX6QDL_CLK_ROM]          = imx_clk_gate2("rom",           "ahb",               base + 0x7c, 0);
	clk[IMX6QDL_CLK_SATA]         = imx_clk_gate2("sata",          "ahb",               base + 0x7c, 4);
	clk[IMX6QDL_CLK_SDMA]         = imx_clk_gate2("sdma",          "ahb",               base + 0x7c, 6);
	clk[IMX6QDL_CLK_SPBA]         = imx_clk_gate2("spba",          "ipg",               base + 0x7c, 12);
	clk[IMX6QDL_CLK_SPDIF]        = imx_clk_gate2_shared("spdif",     "spdif_podf",     base + 0x7c, 14, &share_count_spdif);
	clk[IMX6QDL_CLK_SPDIF_GCLK]   = imx_clk_gate2_shared("spdif_gclk", "ipg",           base + 0x7c, 14, &share_count_spdif);
	clk[IMX6QDL_CLK_SSI1_IPG]     = imx_clk_gate2_shared("ssi1_ipg",      "ipg",        base + 0x7c, 18, &share_count_ssi1);
	clk[IMX6QDL_CLK_SSI2_IPG]     = imx_clk_gate2_shared("ssi2_ipg",      "ipg",        base + 0x7c, 20, &share_count_ssi2);
	clk[IMX6QDL_CLK_SSI3_IPG]     = imx_clk_gate2_shared("ssi3_ipg",      "ipg",        base + 0x7c, 22, &share_count_ssi3);
	clk[IMX6QDL_CLK_SSI1]         = imx_clk_gate2_shared("ssi1",          "ssi1_podf",  base + 0x7c, 18, &share_count_ssi1);
	clk[IMX6QDL_CLK_SSI2]         = imx_clk_gate2_shared("ssi2",          "ssi2_podf",  base + 0x7c, 20, &share_count_ssi2);
	clk[IMX6QDL_CLK_SSI3]         = imx_clk_gate2_shared("ssi3",          "ssi3_podf",  base + 0x7c, 22, &share_count_ssi3);
	clk[IMX6QDL_CLK_UART_IPG]     = imx_clk_gate2("uart_ipg",      "ipg",               base + 0x7c, 24);
	clk[IMX6QDL_CLK_UART_SERIAL]  = imx_clk_gate2("uart_serial",   "uart_serial_podf",  base + 0x7c, 26);
	clk[IMX6QDL_CLK_USBOH3]       = imx_clk_gate2("usboh3",        "ipg",               base + 0x80, 0);
	clk[IMX6QDL_CLK_USDHC1]       = imx_clk_gate2("usdhc1",        "usdhc1_podf",       base + 0x80, 2);
	clk[IMX6QDL_CLK_USDHC2]       = imx_clk_gate2("usdhc2",        "usdhc2_podf",       base + 0x80, 4);
	clk[IMX6QDL_CLK_USDHC3]       = imx_clk_gate2("usdhc3",        "usdhc3_podf",       base + 0x80, 6);
	clk[IMX6QDL_CLK_USDHC4]       = imx_clk_gate2("usdhc4",        "usdhc4_podf",       base + 0x80, 8);
	clk[IMX6QDL_CLK_EIM_SLOW]     = imx_clk_gate2("eim_slow",      "emi_slow_podf",     base + 0x80, 10);
	clk[IMX6QDL_CLK_VDO_AXI]      = imx_clk_gate2("vdo_axi",       "vdo_axi_sel",       base + 0x80, 12);
	clk[IMX6QDL_CLK_VPU_AXI]      = imx_clk_gate2("vpu_axi",       "vpu_axi_podf",      base + 0x80, 14);
	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		clk[IMX6QDL_CLK_PRE0] = imx_clk_gate2("pre0",          "pre_axi",         base + 0x80, 16);
		clk[IMX6QDL_CLK_PRE1] = imx_clk_gate2("pre1",          "pre_axi",         base + 0x80, 18);
		clk[IMX6QDL_CLK_PRE2] = imx_clk_gate2("pre2",          "pre_axi",         base + 0x80, 20);
		clk[IMX6QDL_CLK_PRE3] = imx_clk_gate2("pre3",          "pre_axi",         base + 0x80, 22);
		clk[IMX6QDL_CLK_PRG0_AXI] = imx_clk_gate2_shared("prg0_axi", "ipu1_podf",   base + 0x80, 24, &share_count_prg0);
		clk[IMX6QDL_CLK_PRG1_AXI] = imx_clk_gate2_shared("prg1_axi", "ipu2_podf",   base + 0x80, 26, &share_count_prg1);
		clk[IMX6QDL_CLK_PRG0_APB] = imx_clk_gate2_shared("prg0_apb", "ipg",         base + 0x80, 24, &share_count_prg0);
		clk[IMX6QDL_CLK_PRG1_APB] = imx_clk_gate2_shared("prg1_apb", "ipg",         base + 0x80, 26, &share_count_prg1);
	}
	clk[IMX6QDL_CLK_CKO1]         = imx_clk_gate("cko1",           "cko1_podf",         base + 0x60, 7);
	clk[IMX6QDL_CLK_CKO2]         = imx_clk_gate("cko2",           "cko2_podf",         base + 0x60, 24);

	for (i = 0; i < ARRAY_SIZE(clk); i++)
		if (IS_ERR(clk[i]))
			pr_err("i.MX6q clk %d: register failed with %ld\n",
				i, PTR_ERR(clk[i]));

	clk_data.clks = clk;
	clk_data.clk_num = ARRAY_SIZE(clk);
	of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);

	clk_register_clkdev(clk[IMX6QDL_CLK_GPT_IPG], "ipg", "imx-gpt.0");
	clk_register_clkdev(clk[IMX6QDL_CLK_GPT_IPG_PER], "per", "imx-gpt.0");
	clk_register_clkdev(clk[IMX6QDL_CLK_GPT_3M], "gpt_3m", "imx-gpt.0");
	clk_register_clkdev(clk[IMX6QDL_CLK_ENET_REF], "enet_ref", NULL);

	if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
		imx_clk_set_parent(clk[IMX6QDL_CLK_LDB_DI0_SEL], clk[IMX6QDL_CLK_PLL2_PFD0_352M]);
		imx_clk_set_parent(clk[IMX6QDL_CLK_LDB_DI1_SEL], clk[IMX6QDL_CLK_PLL2_PFD0_352M]);
	}
	/* ipu clock initialization */
	//imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_DI0_PRE_SEL], clk[IMX6QDL_CLK_PLL5_VIDEO_DIV]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_DI0_PRE_SEL],clk[IMX6QDL_CLK_PLL2_PFD0_352M]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_DI1_PRE_SEL], clk[IMX6QDL_CLK_PLL5_VIDEO_DIV]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_DI0_PRE_SEL], clk[IMX6QDL_CLK_PLL5_VIDEO_DIV]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_DI1_PRE_SEL], clk[IMX6QDL_CLK_PLL5_VIDEO_DIV]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_DI0_SEL], clk[IMX6QDL_CLK_IPU1_DI0_PRE]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_DI1_SEL], clk[IMX6QDL_CLK_IPU1_DI1_PRE]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_DI0_SEL], clk[IMX6QDL_CLK_IPU2_DI0_PRE]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_DI1_SEL], clk[IMX6QDL_CLK_IPU2_DI1_PRE]);
	if (cpu_is_imx6dl()) {
		imx_clk_set_rate(clk[IMX6QDL_CLK_PLL3_PFD1_540M], 540000000);
		imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_SEL], clk[IMX6QDL_CLK_PLL3_PFD1_540M]);
		imx_clk_set_parent(clk[IMX6QDL_CLK_AXI_ALT_SEL], clk[IMX6QDL_CLK_PLL3_PFD1_540M]);
		imx_clk_set_parent(clk[IMX6QDL_CLK_AXI_SEL], clk[IMX6QDL_CLK_AXI_ALT_SEL]);
		/* set epdc/pxp axi clock to 200Mhz */
		imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_SEL], clk[IMX6QDL_CLK_PLL2_PFD2_396M]);
		imx_clk_set_rate(clk[IMX6QDL_CLK_IPU2], 200000000);
	} else if (cpu_is_imx6q()) {
		imx_clk_set_parent(clk[IMX6QDL_CLK_IPU1_SEL], clk[IMX6QDL_CLK_MMDC_CH0_AXI]);
		imx_clk_set_parent(clk[IMX6QDL_CLK_IPU2_SEL], clk[IMX6QDL_CLK_MMDC_CH0_AXI]);
		/* set eim_slow to 132Mhz */
		imx_clk_set_rate(clk[IMX6QDL_CLK_EIM_SLOW], 132000000);
	}

	/*
	 * The gpmi needs 100MHz frequency in the EDO/Sync mode,
	 * We can not get the 100MHz from the pll2_pfd0_352m.
	 * So choose pll2_pfd2_396m as enfc_sel's parent.
	 */
	imx_clk_set_parent(clk[IMX6QDL_CLK_ENFC_SEL], clk[IMX6QDL_CLK_PLL2_PFD2_396M]);

	/* gpu clock initilazation */
	/*
	* On mx6dl, 2d core clock sources(sel, podf) is from 3d
	* shader core clock, but 3d shader clock multiplexer of
	* mx6dl is different. For instance the equivalent of
	* pll2_pfd_594M on mx6q is pll2_pfd_528M on mx6dl.
	* Make a note here.
	*/
	if (cpu_is_imx6dl()) {
		imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_SHADER_SEL], clk[IMX6QDL_CLK_PLL2_PFD1_594M]);
		imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_SHADER], 528000000);
		/* for mx6dl, change gpu3d_core parent to 594_PFD*/
		imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_CORE_SEL], clk[IMX6QDL_CLK_PLL2_PFD1_594M]);
		imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_CORE], 528000000);
	} else if (cpu_is_imx6q()) {
		if (imx_get_soc_revision() == IMX_CHIP_REVISION_2_0) {
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_SHADER_SEL], clk[IMX6QDL_CLK_PLL3_PFD0_720M]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_SHADER], 720000000);
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_CORE_SEL], clk[IMX6QDL_CLK_PLL2_PFD1_594M]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_CORE], 594000000);
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU2D_CORE_SEL], clk[IMX6QDL_CLK_PLL3_PFD0_720M]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU2D_CORE], 720000000);
		} else {
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_SHADER_SEL], clk[IMX6QDL_CLK_PLL2_PFD1_594M]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_SHADER], 594000000);
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU3D_CORE_SEL], clk[IMX6QDL_CLK_MMDC_CH0_AXI]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU3D_CORE], 528000000);
			imx_clk_set_parent(clk[IMX6QDL_CLK_GPU2D_CORE_SEL], clk[IMX6QDL_CLK_PLL3_USB_OTG]);
			imx_clk_set_rate(clk[IMX6QDL_CLK_GPU2D_CORE], 480000000);
		}
	}

	/*
	 * Let's initially set up CLKO with OSC24M, since this configuration
	 * is widely used by imx6q board designs to clock audio codec.
	 */
	imx_clk_set_parent(clk[IMX6QDL_CLK_CKO2_SEL], clk[IMX6QDL_CLK_OSC]);
	imx_clk_set_parent(clk[IMX6QDL_CLK_CKO], clk[IMX6QDL_CLK_CKO2]);

	/* Audio-related clocks configuration */
	imx_clk_set_parent(clk[IMX6QDL_CLK_SPDIF_SEL], clk[IMX6QDL_CLK_PLL3_PFD3_454M]);

	/* All existing boards with PCIe use LVDS1 */
	if (IS_ENABLED(CONFIG_PCI_IMX6))
		imx_clk_set_parent(clk[IMX6QDL_CLK_LVDS1_SEL], clk[IMX6QDL_CLK_SATA_REF_100M]);

	/*
	 * Enable clocks only after both parent and rate are all initialized
	 * as needed
	 */
	for (i = 0; i < ARRAY_SIZE(clks_init_on); i++)
		imx_clk_prepare_enable(clk[clks_init_on[i]]);

	if (IS_ENABLED(CONFIG_USB_MXS_PHY)) {
		imx_clk_prepare_enable(clk[IMX6QDL_CLK_USBPHY1_GATE]);
		imx_clk_prepare_enable(clk[IMX6QDL_CLK_USBPHY2_GATE]);
	}

	/*Set enet_ref clock to 125M to supply for RGMII tx_clk */
	clk_set_rate(clk[IMX6QDL_CLK_ENET_REF], 125000000);

#ifdef CONFIG_MX6_VPU_352M
	/*
	 * If VPU 352M is enabled, then PLL2_PDF2 need to be
	 * set to 352M, cpufreq will be disabled as VDDSOC/PU
	 * need to be at highest voltage, scaling cpu freq is
	 * not saving any power, and busfreq will be also disabled
	 * as the PLL2_PFD2 is not at default freq, in a word,
	 * all modules that sourceing clk from PLL2_PFD2 will
	 * be impacted.
	 */
	imx_clk_set_rate(clk[IMX6QDL_CLK_PLL2_PFD2_396M], 352000000);
	imx_clk_set_parent(clk[IMX6QDL_CLK_VPU_AXI_SEL], clk[IMX6QDL_CLK_PLL2_PFD2_396M]);
	pr_info("VPU 352M is enabled!\n");
#endif

	imx6q_set_lpm(WAIT_CLOCKED);

}
CLK_OF_DECLARE(imx6q, "fsl,imx6q-ccm", imx6q_clocks_init);
