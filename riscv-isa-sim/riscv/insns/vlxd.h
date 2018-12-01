require_extension('V');
require_rv64;
vreg_t load_value;
switch(EW)
{
  case MaxElementWidth8:
    load_value.e8[0] = MMU.load_uint8(RS1 + insn.vi_imm() + (VRS2.e8[0] << MemByteOffset8));
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        load_value.e8[i] = MMU.load_uint8(RS1 + insn.vi_imm() + (VRS2.e8[i] << MemByteOffset8));
      }
    }
  case MaxElementWidth16:
    load_value.e16[0] = MMU.load_uint16(RS1 + insn.vi_imm() + (VRS2.e16[0] << MemByteOffset16));
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        load_value.e16[i] = MMU.load_uint16(RS1 + insn.vi_imm() + (VRS2.e16[i] << MemByteOffset16));
      }
    }
    break;
  case MaxElementWidth32:
    load_value.e32[0] = MMU.load_uint32(RS1 + insn.vi_imm() + (VRS2.e32[0] << MemByteOffset32));
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        load_value.e32[i] = MMU.load_uint32(RS1 + insn.vi_imm() + (VRS2.e32[i] << MemByteOffset32));
      }
    }
    break;
  case MaxElementWidth64:
    load_value.e64[0] = MMU.load_uint64(RS1 + insn.vi_imm() + (VRS2.e64[0] << MemByteOffset64));
    if(insn.m())
    {
      for(reg_t i = 1; i < VL; ++i)
      {
        load_value.e64[i] =  MMU.load_uint64(RS1 + insn.vi_imm() + (VRS2.e64[i] << MemByteOffset64));
      }
    }
    break;
}
WRITE_VRD(v_load(load_value, EW, insn.m(), VMASK, VL));
