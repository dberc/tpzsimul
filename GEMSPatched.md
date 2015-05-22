# Using TOPAZ in a  Modified version of GEMS #

Thats true, no one has a untouched GEMS. Next we will provide a short guide that explains how to merge your a non-original GEMS branch with TOPAZ. In order to do it we will assume using the Windriver version of GEMS, whcih supports Simics 4+.

Lets assume that `$GEMS_MODIFIED` points to the directory where patched GEMS is located and $GEMS the directory downloaded from our repository. To apply it

```shell

#Example used as MODIFIED version of GEMS
shell$ tar xzvf gems-release2.1.1.tar.gz
shell$ mv ./gems-2.1.1/ $GEMS_MODIFIED
shell$ wget "http://www.cs.wisc.edu/gems/patches/gems2.1.1_patch1.tgz"
shell$ tar xzvf gems2.1.1_patch1.tgz
shell$ cd $GEMS_MODIFIED
shell$ patch -p1 < ../patched/patches/flatten.patch
shell$ patch -p1 < ../patched/patches/compiler.update
shell$ patch -p1 < ../patched/patches/make.x86.target.work
```

Now you have a Simics 4.0 ready to run ruby (opal does not work). Lets assume we are using Simics 4.2. We edit `common/Makefile.simics_version` to reflect that and create a workspace in `$GEMS_ROOT/simics_42_workspace`. Execute `$GEMS_ROOT/scripts/make_symlinks.sh` and you will be ready to compile

# Merging with GEMS-TOPAZ #

We need to use mercurial. For the previous example, we create a new repository within:

```
shell$ cd $GEMS_MODIFIED
shell$ hg init .
shell$ echo ".DS_Store
.*
*slicc*
*simics*
*generated*
*html*
*.pyc
*.defaults*" >>.hgignore
shell$ hg add *
shell$ hg commit  -m "My Modified GEMS"
```

Now we can merge with previously cloned GEMS repository:

```
shell$ cd $GEMS_MODIFIED
shell$ hg pull -f $GEMS
shell$ hg merge -r tip -t kdiff3
... (Be patient here. Probably it is a good idea to get a list of files touched by topaz integration)
```

A guide to merge all files is provided [here](http://hgbook.red-bean.com/read/a-tour-of-mercurial-merging-work.html)

In this particular case (simics4.0 patch), it is necessary to modify `$(GEMS_MODIFIED)/ruby/module/Makefile` to link `ruby.so` against `libtpz.a`

# Future Modifications of TOPAZ interface #

To download future TOPAZ integration to your modified of GEMS, you could use [Hg Transplant extension](http://mercurial.selenic.com/wiki/TransplantExtension)