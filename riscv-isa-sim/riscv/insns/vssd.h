require_extension('V');
require_rv64;

switch(EW)
{
  case MaxElementWidth8:
    MMU.store_uint8(RS1 + insn.vs_imm(), VRS3.e8[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        if(RS2)
          MMU.store_uint8(RS1 + insn.vs_imm() + ((i * RS2) << MemByteOffset8) , VRS3.e8[i]);
        else
          MMU.store_uint8(RS1 + insn.vs_imm() + (i << MemByteOffset8) , VRS3.e8[i]);
      }
    }
    break;
  case MaxElementWidth16:
   MMU.store_uint16(RS1 + insn.vs_imm(), VRS3.e16[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        if(RS2)
          MMU.store_uint16(RS1 + insn.vs_imm() + ((i * RS2) << MemByteOffset16) , VRS3.e16[i]);
        else
          MMU.store_uint16(RS1 + insn.vs_imm() + (i << MemByteOffset16) , VRS3.e16[i]);
      }
    }
    break;
  case MaxElementWidth32:
   MMU.store_uint32(RS1 + insn.vs_imm(), VRS3.e32[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        if(RS2)
          MMU.store_uint32(RS1 + insn.vs_imm() + ((i * RS2) << MemByteOffset32) , VRS3.e32[i]);
        else
          MMU.store_uint32(RS1 + insn.vs_imm() + (i << MemByteOffset32) , VRS3.e32[i]);
      }
    }
    break;
  case MaxElementWidth64:
    MMU.store_uint64(RS1 + insn.vs_imm(), VRS3.e64[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        if(RS2)
          MMU.store_uint64(RS1 + insn.vs_imm() + ((i * RS2) << MemByteOffset64) , VRS3.e64[i]);
        else
          MMU.store_uint64(RS1 + insn.vs_imm() + (i << MemByteOffset64) , VRS3.e64[i]);
      }
    }
    break;
}
