require_extension('V');
require_rv64;

switch(EW)
{
  case MaxElementWidth8:
    MMU.store_uint8(RS1 + (VRS2.e8[0] << MemByteOffset8) + insn.vs_imm(), VRS3.e8[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        MMU.store_uint8(RS1 + insn.vs_imm() + ((VRS2.e8[i]) << MemByteOffset8) , VRS3.e8[i]);
      }
    }
    break;
  case MaxElementWidth16:
   MMU.store_uint16(RS1 + (VRS2.e16[0] << MemByteOffset16) + insn.vs_imm(), VRS3.e16[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        MMU.store_uint16(RS1 + insn.vs_imm() + ((VRS2.e16[i]) << MemByteOffset16), VRS3.e16[i]);
      }
    }
    break;
  case MaxElementWidth32:
   MMU.store_uint32(RS1+ ((VRS2.e32[0]) << MemByteOffset32) + insn.vs_imm(), VRS3.e32[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        MMU.store_uint32(RS1 + insn.vs_imm() + ((VRS2.e32[i]) << MemByteOffset32) , VRS3.e32[i]);
      }
    }
    break;
  case MaxElementWidth64:
    MMU.store_uint64(RS1 + ((VRS2.e64[0]) << MemByteOffset64) + insn.vs_imm(), VRS3.e64[0]);
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        MMU.store_uint64(RS1 + insn.vs_imm() + ((VRS2.e64[i]) << MemByteOffset64) , VRS3.e64[i]);
      }
    }
    break;
}
