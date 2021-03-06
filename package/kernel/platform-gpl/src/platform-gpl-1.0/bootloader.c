/********** COPYRIGHT AND CONFIDENTIALITY INFORMATION NOTICE *************
** Copyright (c) 2014 - Technicolor Delivery Technologies, SAS          **
** All Rights Reserved                                                  **
**                                                                      **
** This program is free software; you can redistribute it and/or modify **
** it under the terms of the GNU General Public License version 2 as    **
** published by the Free Software Foundation.                           **
*************************************************************************/

#include <linux/version.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/proc_fs.h>
#include <linux/mtd/map.h>
#include <linux/mtd/mtd.h>


#define BOOTLOADER_DIR_NAME		"bootloader"
#define BOOTLOADER_VERSION_ENTRY	"version"

#define BLVERSION_PARTITION		"blversion"
#define BLVERSION_SIZE			3

struct proc_dir_entry *bootloader_dir;
struct proc_dir_entry *bootloader_proc;

static unsigned char blversion[BLVERSION_SIZE];


static int bootloader_proc_read(char *page, char **start, off_t offset, int count, int *eof, void *data)
{
	int len = 0;

	len = sprintf(page, "%u.%u.%u\n", (unsigned int)blversion[0], (unsigned int)blversion[1], (unsigned int)blversion[2]);

	*eof = 1;
	return (len < count) ? len : 0;
}

static int bootloader_init_proc( void )
{
	bootloader_dir = proc_mkdir(BOOTLOADER_DIR_NAME, NULL );

	if (bootloader_dir == NULL) {
		remove_proc_entry(BOOTLOADER_DIR_NAME, NULL);
		printk(KERN_ALERT "Error: Could not initialize proc entry\n");
		return -ENOMEM;
	}

	bootloader_proc = create_proc_entry(BOOTLOADER_VERSION_ENTRY, 0444, bootloader_dir);
	if (bootloader_proc == NULL) {
		remove_proc_entry(BOOTLOADER_VERSION_ENTRY, bootloader_dir);
		printk(KERN_ALERT "Error: Could not initialize proc entry\n");
		return -ENOMEM;
	}
	bootloader_proc->read_proc   = bootloader_proc_read;

	return 0;
}

static int bootloader_cleanup_proc( void )
{
	remove_proc_entry(BOOTLOADER_VERSION_ENTRY, bootloader_dir);
	remove_proc_entry(BOOTLOADER_DIR_NAME, NULL);
	return 0;
}

static struct mtd_info *mtd;
int bootloader_init (void )
{
	int err;
	size_t retlen;

	mtd = get_mtd_device_nm(BLVERSION_PARTITION);
	if (mtd == ERR_PTR(-ENODEV)) {
		printk("Could not access blversion MTD partition\n");
		return -ENODEV;
	}

	err = mtd_read(mtd, 0x0, BLVERSION_SIZE, &retlen, blversion);

	if (err || (BLVERSION_SIZE != retlen)) {
		printk("Could not read blversion\n");
		return -EIO;
	}

	/* Create the proc entries for bootloader */
	err = bootloader_init_proc();
	if (err != 0) {
		return err;
	}

	return 0;
}

void bootloader_cleanup( void )
{
	bootloader_cleanup_proc();
	put_mtd_device(mtd);
	mtd = 0;
}

