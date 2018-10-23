# ft_printf
This is my implementation of standard 42School's project ft_printf which consists of recoding libc function printf().


**Mandatory part:**

• Manage the following conversions: sSpdDioOuUxXcC.

• Manage %%.

• Manage the flags #0-+ and space.

• Manage the minimum field width.

• Manage the precision.

• Manage the flags (length modifiers): hh, h, l, ll, j, and z.


**As a bonus part following features were added:**

• Handling conversions: fF.

• Handling binary conversion %b (non-existing in printf()).

• Handling flag * for minimum field width and precision.

• Added function ft_dprintf() as analog to dprintf for writing output directly to specified file descriptor.

• Output managed with output buffer so ft_printf() function works at about **100-110% speed** of original printf().
