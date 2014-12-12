/*
   eXokernel Development Kit (XDK)

   Based on code by Samsung Research America Copyright (C) 2013
 
   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.

   As a special exception, if you link the code in this file with
   files compiled with a GNU compiler to produce an executable,
   that does not cause the resulting executable to be covered by
   the GNU Lesser General Public License.  This exception does not
   however invalidate any other reasons why the executable file
   might be covered by the GNU Lesser General Public License.
   This exception applies to code released by its copyright holders
   in files containing the exception.  
*/

#include <component/base.h>
#include <dlfcn.h>
#include <stdio.h>

#include "dummy_block_device.h"


int main()
{
  Component::IBase * comp = Component::load_component("./libcomp_dummybd.so.1",
                                                      DummyBlockDeviceComponent::component_id());

  IBlockDevice * itf = (IBlockDevice *) comp->query_interface(IBlockDevice::iid());

  itf->init_device(0);
  Exokernel::Device * dev = itf->get_device();

  itf->sync_read_block(0,0,0,0,0);
  itf->sync_write_block(0,0,0,0,0);

  itf->shutdown_device();

  itf->release_ref();
  return 0;
}
