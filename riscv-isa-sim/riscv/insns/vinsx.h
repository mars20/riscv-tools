require_extension('V');
require_rv64;
WRITE_VRD(v_insert(VRD, RS1, RS2, EW, VL, VMASK, insn.m()));
