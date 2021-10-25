
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/gpio.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/of_gpio.h>
#include <linux/semaphore.h>
#include <linux/timer.h>
#include <linux/irq.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/fs.h>
#include <linux/fcntl.h>
#include <linux/platform_device.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/pci.h>
#include <linux/ioport.h>

 

static void pci_release(struct device *dev)
{

    printk("pci device released!\r\n");
}


static struct platform_device pci_device = {
    .name = "pci_skel_9",
    .id = 10,
    .dev = {
    .release = &pci_release,
 },
     
     
 
};


static int pci_probe(struct platform_device *dev)
{

    printk("pci driver and device has matched!\r\n");

    return  0;
}

static struct platform_driver pci_driver = {

    .driver={
    .name ="pci_skel_9",
    },
    .probe = pci_probe,
    
/* 驱动名字，用于和设备匹配 */
 
 };


static int __init pci_init(void)
{
    platform_driver_register(&pci_driver);
    platform_device_register(&pci_device);
    return 0;
}



static void __exit pci_exit(void)
{
     platform_driver_unregister(&pci_driver);
     platform_device_unregister(&pci_device);
}






module_init(pci_init);
module_exit(pci_exit);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("jyf");


