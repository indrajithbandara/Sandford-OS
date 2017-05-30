version   = "0.0.8";
bnf       = open("buildnum", "r");
prevbuild = int(bnf.read());
bnf.close();
build     = prevbuild + 1;
bnf       = open("buildnum", "w");
bnf.write(str(build));
bnf.close();

print("Building Sandford " + version + " Build " + str(build));
