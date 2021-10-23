#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h>    /* for the character device support*/

int assgn2_open (struct inode *pinode ,struct file *pfile){
 
   printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
   return 0;

}

ssize_t assgn2_read(struct file *pfile, char __user *buffer ,size_t length, loff_t *offset)
{

   printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
   return 0;
}

ssize_t assgn2_write(struct file *pfile, const char __user *buffer ,size_t length, loff_t *offset)
{

   printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
   return length;
}

int assgn2_close (struct inode *pinode,struct file *pfile){
 
   printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
   return 0;

}              
/* To hold the file operations performed on this device*/

struct file_operations assgn2_file_operations = {

     .owner  =  THIS_MODULE,
     .open   =  assgn2_open,
     .read   =  assgn2_read,
     .write  =  assgn2_write,
     .release = assgn2_close,
                  
};

int assgn2_simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

/* Register with the kernel and indicate that we are registering a character device driver */
    register_chrdev(240/* Major Number */,
                     "Simple Char Drv"    /* Name of the driver */,
                     &assgn2_file_operations    /* File Operations */ );

    return 0;

}

void assgn2_simple_module_exit(void)
{

   printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

   /* Unregister the character device driver */

   unregister_chrdev(240,"Simple Char Dev");
}
module_init(assgn2_simple_module_init);
module_exit(assgn2_simple_module_exit);

MODULE_LICENSE("GFL");
MODULE_AUTHOR("Group 21");
MODULE_DESCRIPTION("Character device driver");



