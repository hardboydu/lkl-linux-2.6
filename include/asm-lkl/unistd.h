#ifndef _ASM_LKL_UNISTD_H
#define _ASM_LKL_UNISTD_H


/*
 * FIXME: get rid of all this kludge and keep only the linux_syscall interface.
 */
#define cond_syscall(x) 

#include <asm-i386/unistd.h>

#undef __ARCH_WANT_SYS_SIGPROCMASK

#ifndef __KERNEL__

#include <asm/linkage.h>
#undef __KERNEL_STRICT_NAMES
#include <linux/types.h>

#include <asm/poll.h>
#include <asm/stat.h>
#include <asm/fcntl.h>
#include <linux/time.h>
#include <asm-generic/statfs.h>
#include <linux/stat.h>

struct linux_dirent {
	unsigned long	d_ino;
	unsigned long	d_off;
	unsigned short	d_reclen;
	char		d_name[1];
};

asmlinkage long sys_sync(void);
asmlinkage long sys_reboot(int magic1, int magic2, unsigned int cmd,  void __user *arg);
asmlinkage ssize_t sys_write(unsigned int fd, const char __user *buf,    size_t count);
asmlinkage long sys_close(unsigned int fd);
asmlinkage long sys_unlink(const char __user *pathname);
asmlinkage long sys_open(const char __user *filename, int flags, int mode);
asmlinkage long sys_poll(struct pollfd __user *ufds, unsigned int nfds, long timeout);
asmlinkage ssize_t sys_read(unsigned int fd, char __user *buf,  size_t count);
asmlinkage off_t sys_lseek(unsigned int fd, off_t offset,  unsigned int origin);
asmlinkage long sys_rename(const char __user *oldname,  const char __user *newname);
asmlinkage long sys_flock(unsigned int fd, unsigned int cmd);
asmlinkage long sys_newfstat(unsigned int fd, struct stat __user *statbuf);
asmlinkage long sys_chmod(const char __user *filename, mode_t mode);
asmlinkage long sys_newlstat(char __user *filename, struct stat __user *statbuf);
asmlinkage long sys_mkdir(const char __user *pathname, int mode);
asmlinkage long sys_rmdir(const char __user *pathname);
asmlinkage long sys_getdents(unsigned int fd, struct linux_dirent __user *dirent, unsigned int count);
asmlinkage long sys_newstat(char __user *filename, struct stat __user *statbuf);
asmlinkage long sys_utimes(const char __user *filename, struct timeval __user *utimes);
asmlinkage long sys_nanosleep(struct timespec __user *rqtp, struct timespec __user *rmtp);
asmlinkage long sys_mknod(const char __user *filename, int mode,
				unsigned dev);
asmlinkage long sys_umount(char __user *name, int flags);
asmlinkage long sys_chdir(const char __user *filename);
asmlinkage long sys_statfs(const char __user * path,
				struct statfs __user *buf);
asmlinkage long sys_chroot(const char __user *filename);
asmlinkage long sys_safe_mount(char __user *dev_name, char __user *dir_name,
				char __user *type, unsigned long flags,
				void __user *data);


extern int sprintf(char * buf, const char * fmt,
		   ...) __attribute__ ((format (printf, 2, 3)));
extern int snprintf(char * buf, size_t size, const char * fmt,
		    ...) __attribute__ ((format (printf, 3, 4)));
extern int sscanf(const char *, const char *,
		  ...) __attribute__ ((format (scanf, 2, 3)));

#endif 

#define __NR_safe_mount __NR_mount 
#define __NR_newstat __NR_stat
#define __NR_newfstat __NR_fstat
#define __NR_newlstat __NR_lstat


#endif
