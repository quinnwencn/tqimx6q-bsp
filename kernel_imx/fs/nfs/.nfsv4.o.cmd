cmd_fs/nfs/nfsv4.o := arm-linux-gnueabihf-ld -EL    -r -o fs/nfs/nfsv4.o fs/nfs/nfs4proc.o fs/nfs/nfs4xdr.o fs/nfs/nfs4state.o fs/nfs/nfs4renewd.o fs/nfs/nfs4super.o fs/nfs/nfs4file.o fs/nfs/delegation.o fs/nfs/nfs4idmap.o fs/nfs/callback.o fs/nfs/callback_xdr.o fs/nfs/callback_proc.o fs/nfs/nfs4namespace.o fs/nfs/nfs4getroot.o fs/nfs/nfs4client.o fs/nfs/nfs4session.o fs/nfs/dns_resolve.o fs/nfs/nfs4trace.o fs/nfs/cache_lib.o fs/nfs/nfs4sysctl.o 
