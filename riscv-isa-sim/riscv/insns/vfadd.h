require_extension('V');
require_rv64;
WRITE_VRD(v_fadd(VRS1, VRS2, EW, insn.m(), VMASK, VL));
