require_extension('V');
require_rv64;
WRITE_VRD(v_bcast(VRS1, RS2, EW, 0, VMASK, VL));
