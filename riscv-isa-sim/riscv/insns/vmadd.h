require_extension('V');
require_rv64;
WRITE_VRD(v_madd(VRS1, VRS2, VRS3, EW, insn.m(), VMASK, VL));
