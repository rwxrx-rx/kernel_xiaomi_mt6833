// FT8722 panel compat globals for flyme base.
// The camellia FT8722 panel driver references these display globals that the
// original cristidclxvi camellia display stack defined elsewhere. The flyme
// base kernel does not define them, so provide weak fallbacks here. If any
// other translation unit provides a strong definition, that one wins.
#include <linux/types.h>
#include <linux/export.h>

int real_refresh __attribute__((weak)) = 60;
EXPORT_SYMBOL(real_refresh);

int temp_refresh __attribute__((weak)) = 60;
EXPORT_SYMBOL(temp_refresh);

bool esd_flag __attribute__((weak)) = false;
EXPORT_SYMBOL(esd_flag);

int lcm_name[10] __attribute__((weak));
EXPORT_SYMBOL(lcm_name);
