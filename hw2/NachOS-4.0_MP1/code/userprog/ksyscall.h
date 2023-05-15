/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"

#include "synchconsole.h"

OpenFileId SysOpen(char *name)
{
  return kernel->fileSystem->OpenAFile(name);
}

int SysWrite(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->Write(buffer, size, id);
}

int SysRead(char *buffer, int size, OpenFileId id)
{
  return kernel->fileSystem->Read(buffer, size, id);
}

int SysClose(OpenFileId id)
{
  return kernel->fileSystem->Close(id);
}

void SysHalt()
{
  kernel->interrupt->Halt();
}

void SysPrintInt(int number)
{
  kernel->synchConsoleOut->PutInt(number);
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

#ifdef FILESYS_STUB
int SysCreate(char *filename)
{
  // return value
  // 1: success
  // 0: failed
  return kernel->interrupt->CreateFile(filename);
}
#else
int SysCreate(char *filename, int initialSize)
{
  // return value
  // 1: success
  // 0: failed
  return kernel->interrupt->CreateFile(filename, initialSize);
}
#endif

#endif /* ! __USERPROG_KSYSCALL_H__ */
