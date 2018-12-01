require_extension('V');
require_rv64;
WRITE_VRD(v_merge(VRS1, VRS2, EW, VL, VMASK, insn.m()));
