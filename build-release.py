from subprocess import call

version   = "0.0.8";
bnf       = open("buildnum", "r");
prevbuild = int(bnf.read());
bnf.close();
build     = prevbuild + 1;
bnf       = open("buildnum", "w");
bnf.write(str(build));
bnf.close();

print("Building Release " + version + " (Build " + str(build) + ")");
print("Compiling Userland...");
call(["./scripts/build-utits.sh"]);
call(["./scripts/build-sys.sh"]);
#print("Creating Disk Image...");
#call(["mkisofs", "-o", "SANDFORD-RELEASE-" + version + "-BUILD-" + str(build) + ".ISO", "./"]);
