let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <S-Tab> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404228)
inoremap <silent> <S-Tab> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404227)
cnoremap <silent> <Down> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404222)
inoremap <silent> <Down> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404221)
inoremap <silent> <C-Space> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404216)
inoremap <silent> <expr> <Plug>(cmp.utils.keymap.evacuate:) v:lua.MPairs.completion_confirm()
cnoremap <silent> <Up> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404210)
inoremap <silent> <Up> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404209)
cnoremap <silent> <Plug>(TelescopeFuzzyCommandSearch) e "lua require('telescope.builtin').command_history { default_text = [=[" . escape(getcmdline(), '"') . "]=] }"
noremap! <silent> <Plug>luasnip-delete-check <Cmd>lua require'luasnip'.unlink_current_if_deleted()
inoremap <silent> <Plug>luasnip-jump-prev <Cmd>lua require'luasnip'.jump(-1)
inoremap <silent> <Plug>luasnip-jump-next <Cmd>lua require'luasnip'.jump(1)
inoremap <silent> <Plug>luasnip-prev-choice <Cmd>lua require'luasnip'.change_choice(-1)
inoremap <silent> <Plug>luasnip-next-choice <Cmd>lua require'luasnip'.change_choice(1)
inoremap <silent> <Plug>luasnip-expand-snippet <Cmd>lua require'luasnip'.expand()
inoremap <silent> <Plug>luasnip-expand-or-jump <Cmd>lua require'luasnip'.expand_or_jump()
inoremap <silent> <M-Down> j
inoremap <silent> <M-j> :m .+1==gi
inoremap <silent> <M-Up> k
inoremap <silent> <M-k> :m .-2==gi
inoremap <silent> <M-Right> l
inoremap <silent> <M-Left> h
nnoremap <silent>  h
tnoremap <silent>  h
snoremap <silent> 	 <Cmd>call v:lua.cmp.utils.keymap.set_map(23404220)
nnoremap <silent> <NL> j
tnoremap <silent> <NL> j
nnoremap <silent>  k
tnoremap <silent>  k
tnoremap <silent>  l
nnoremap <silent>  l
nnoremap <silent>  :call QuickFixToggle()
nnoremap <silent>  :w
nnoremap <silent>  <Cmd>execute v:count . "ToggleTerm"
nnoremap <silent> Þ <Nop>
nnoremap <silent>  <Cmd>lua require("which-key").show("", {mode = "n", auto = true})
nnoremap <silent>  Þ <Nop>
nnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "n", auto = true})
nnoremap <silent>  lpÞ <Nop>
nnoremap <silent>  lÞ <Nop>
nnoremap <silent>  sÞ <Nop>
nnoremap <silent>  TÞ <Nop>
nnoremap <silent>  gÞ <Nop>
nnoremap <silent>  LlÞ <Nop>
nnoremap <silent>  LÞ <Nop>
nnoremap <silent>  bÞ <Nop>
nnoremap <silent>  pÞ <Nop>
xnoremap <silent>  Þ <Nop>
xnoremap <silent>   <Cmd>lua require("which-key").show(" ", {mode = "v", auto = true})
vnoremap <nowait> <silent>  / <Cmd>lua ___comment_gc(vim.fn.visualmode())
nnoremap <nowait> <silent>  pc <Cmd>PackerCompile
nnoremap <nowait> <silent>  pS <Cmd>PackerStatus
nnoremap <nowait> <silent>  pr <Cmd>lua require('lvim.plugin-loader').recompile()
nnoremap <nowait> <silent>  pu <Cmd>PackerUpdate
nnoremap <nowait> <silent>  ps <Cmd>PackerSync
nnoremap <nowait> <silent>  pi <Cmd>PackerInstall
nnoremap <nowait> <silent>  lpt <Cmd>lua require('lvim.lsp.peek').Peek('typeDefinition')
nnoremap <nowait> <silent>  lpi <Cmd>lua require('lvim.lsp.peek').Peek('implementation')
nnoremap <nowait> <silent>  lpd <Cmd>lua require('lvim.lsp.peek').Peek('definition')
nnoremap <nowait> <silent>  la <Cmd>lua require('lvim.core.telescope').code_actions()
nnoremap <nowait> <silent>  lk <Cmd>lua vim.lsp.diagnostic.goto_prev({popup_opts = {border = lvim.lsp.popup_border}})
nnoremap <nowait> <silent>  ld <Cmd>Telescope lsp_document_diagnostics
nnoremap <nowait> <silent>  lw <Cmd>Telescope lsp_workspace_diagnostics
nnoremap <nowait> <silent>  lj <Cmd>lua vim.lsp.diagnostic.goto_next({popup_opts = {border = lvim.lsp.popup_border}})
nnoremap <nowait> <silent>  ll <Cmd>lua vim.lsp.codelens.run()
nnoremap <nowait> <silent>  lI <Cmd>LspInstallInfo
nnoremap <nowait> <silent>  lr <Cmd>lua vim.lsp.buf.rename()
nnoremap <nowait> <silent>  ls <Cmd>Telescope lsp_document_symbols
nnoremap <nowait> <silent>  lS <Cmd>Telescope lsp_dynamic_workspace_symbols
nnoremap <nowait> <silent>  lq <Cmd>lua vim.lsp.diagnostic.set_loclist()
nnoremap <nowait> <silent>  lf <Cmd>lua vim.lsp.buf.formatting()
nnoremap <nowait> <silent>  li <Cmd>LspInfo
nnoremap <nowait> <silent>  h <Cmd>nohlsearch
nnoremap <nowait> <silent>  ; <Cmd>Dashboard
nnoremap <nowait> <silent>  w <Cmd>w!
nnoremap <nowait> <silent>  sp <Cmd>lua require('telescope.builtin.internal').colorscheme({enable_preview = true})
nnoremap <nowait> <silent>  sh <Cmd>Telescope help_tags
nnoremap <nowait> <silent>  sr <Cmd>Telescope oldfiles
nnoremap <nowait> <silent>  sC <Cmd>Telescope commands
nnoremap <nowait> <silent>  sk <Cmd>Telescope keymaps
nnoremap <nowait> <silent>  sM <Cmd>Telescope man_pages
nnoremap <nowait> <silent>  sb <Cmd>Telescope git_branches
nnoremap <nowait> <silent>  sc <Cmd>Telescope colorscheme
nnoremap <nowait> <silent>  sR <Cmd>Telescope registers
nnoremap <nowait> <silent>  sf <Cmd>Telescope find_files
nnoremap <nowait> <silent>  st <Cmd>Telescope live_grep
nnoremap <nowait> <silent>  / <Cmd>lua require('Comment').toggle()
nnoremap <nowait> <silent>  be <Cmd>BufferCloseAllButCurrent
nnoremap <nowait> <silent>  bl <Cmd>BufferCloseBuffersRight
nnoremap <nowait> <silent>  bh <Cmd>BufferCloseBuffersLeft
nnoremap <nowait> <silent>  bw <Cmd>BufferWipeout
nnoremap <nowait> <silent>  bj <Cmd>BufferPick
nnoremap <nowait> <silent>  bb <Cmd>b#
nnoremap <nowait> <silent>  bL <Cmd>BufferOrderByLanguage
nnoremap <nowait> <silent>  bD <Cmd>BufferOrderByDirectory
nnoremap <nowait> <silent>  bf <Cmd>Telescope buffers
nnoremap <nowait> <silent>  gp <Cmd>lua require 'gitsigns'.preview_hunk()
nnoremap <nowait> <silent>  gl <Cmd>lua require 'gitsigns'.blame_line()
nnoremap <nowait> <silent>  gr <Cmd>lua require 'gitsigns'.reset_hunk()
nnoremap <nowait> <silent>  gj <Cmd>lua require 'gitsigns'.next_hunk()
nnoremap <nowait> <silent>  gs <Cmd>lua require 'gitsigns'.stage_hunk()
nnoremap <nowait> <silent>  go <Cmd>Telescope git_status
nnoremap <nowait> <silent>  gk <Cmd>lua require 'gitsigns'.prev_hunk()
nnoremap <nowait> <silent>  gb <Cmd>Telescope git_branches
nnoremap <nowait> <silent>  gc <Cmd>Telescope git_commits
nnoremap <nowait> <silent>  gC <Cmd>Telescope git_bcommits
nnoremap <nowait> <silent>  gR <Cmd>lua require 'gitsigns'.reset_buffer()
nnoremap <nowait> <silent>  gu <Cmd>lua require 'gitsigns'.undo_stage_hunk()
nnoremap <nowait> <silent>  gd <Cmd>Gitsigns diffthis HEAD
nnoremap <nowait> <silent>  c <Cmd>BufferClose!
nnoremap <nowait> <silent>  Ti :TSConfigInfo
nnoremap <nowait> <silent>  e <Cmd>NvimTreeToggle
nnoremap <nowait> <silent>  q <Cmd>q!
nnoremap <nowait> <silent>  f <Cmd>Telescope find_files
nnoremap <nowait> <silent>  LI <Cmd>lua require('lvim.core.telescope.custom-finders').view_lunarvim_changelog()
nnoremap <nowait> <silent>  Llp <Cmd>lua require('lvim.core.terminal').toggle_log_view('packer.nvim')
nnoremap <nowait> <silent>  Lll <Cmd>lua require('lvim.core.terminal').toggle_log_view(vim.lsp.get_log_path())
nnoremap <nowait> <silent>  Lld <Cmd>lua require('lvim.core.terminal').toggle_log_view(require('lvim.core.log').get_path())
nnoremap <nowait> <silent>  LlN <Cmd>edit $NVIM_LOG_FILE
nnoremap <nowait> <silent>  LlP <Cmd>exe 'edit '.stdpath('cache').'/packer.nvim.log'
nnoremap <nowait> <silent>  LlL <Cmd>lua vim.fn.execute('edit ' .. vim.lsp.get_log_path())
nnoremap <nowait> <silent>  LlD <Cmd>lua vim.fn.execute('edit ' .. require('lvim.core.log').get_path())
nnoremap <nowait> <silent>  Lln <Cmd>lua require('lvim.core.terminal').toggle_log_view(os.getenv('NVIM_LOG_FILE'))
nnoremap <nowait> <silent>  Lr <Cmd>LvimReload
nnoremap <nowait> <silent>  Lk <Cmd>lua require('lvim.keymappings').print()
nnoremap <nowait> <silent>  Lg <Cmd>lua require('lvim.core.telescope.custom-finders').grep_lunarvim_files()
nnoremap <nowait> <silent>  Lc <Cmd>edit /home/diego/.config/lvim/config.lua
nnoremap <nowait> <silent>  Lu <Cmd>LvimUpdate
nnoremap <nowait> <silent>  Lf <Cmd>lua require('lvim.core.telescope.custom-finders').find_lunarvim_files()
nnoremap <nowait> <silent>  Li <Cmd>lua require('lvim.core.info').toggle_popup(vim.bo.filetype)
nnoremap <silent>  gg <Cmd>lua require('lvim.core.terminal')._exec_toggle('lazygit')
nnoremap <silent> " <Cmd>lua require("which-key").show("\"", {mode = "n", auto = true})
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
nnoremap <silent> ' <Cmd>lua require("which-key").show("'", {mode = "n", auto = true})
vnoremap <silent> < <gv
vnoremap <silent> > >gv
nnoremap <silent> @Þ <Nop>
nnoremap <silent> @ <Cmd>lua require("which-key").show("@", {mode = "n", auto = true})
nnoremap <silent> H :BufferPrevious
xnoremap <silent> J :move '>+1gv-gv
xnoremap <silent> K :move '<-2gv-gv
nnoremap <silent> L :BufferNext
nnoremap Y y$
nnoremap <silent> [Þ <Nop>
nnoremap <silent> [ <Cmd>lua require("which-key").show("[", {mode = "n", auto = true})
xnoremap <silent> [Þ <Nop>
xnoremap <silent> [ <Cmd>lua require("which-key").show("[", {mode = "v", auto = true})
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
nnoremap <silent> [q :cprev
nnoremap <silent> ]Þ <Nop>
nnoremap <silent> ] <Cmd>lua require("which-key").show("]", {mode = "n", auto = true})
xnoremap <silent> ]Þ <Nop>
xnoremap <silent> ] <Cmd>lua require("which-key").show("]", {mode = "v", auto = true})
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
nnoremap <silent> ]q :cnext
nnoremap <silent> ` <Cmd>lua require("which-key").show("`", {mode = "n", auto = true})
xnoremap <silent> aÞ <Nop>
xnoremap <silent> a <Cmd>lua require("which-key").show("a", {mode = "v", auto = true})
xmap a% <Plug>(MatchitVisualTextObject)
xnoremap <silent> gb <Cmd>lua ___comment_gb(vim.fn.visualmode())
xnoremap <silent> gc <Cmd>lua ___comment_gc(vim.fn.visualmode())
nnoremap <silent> gb <Cmd>lua ___comment_call("gb")g@
nnoremap <silent> gc <Cmd>lua ___comment_call("gc")g@
nnoremap <silent> gbc <Cmd>lua ___comment_call("gbc")g@$
nnoremap <silent> <expr> gcc v:count == 0 ? '<Cmd>lua ___comment_call("gcc")g@$' : '<Cmd>lua ___comment_count_gcc()'
nnoremap <silent> gÞ <Nop>
nnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "n", auto = true})
xnoremap <silent> gÞ <Nop>
xnoremap <silent> g <Cmd>lua require("which-key").show("g", {mode = "v", auto = true})
xmap gx <Plug>NetrwBrowseXVis
nmap gx <Plug>NetrwBrowseX
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
xnoremap <silent> iÞ <Nop>
xnoremap <silent> i <Cmd>lua require("which-key").show("i", {mode = "v", auto = true})
nnoremap <silent> zÞ <Nop>
nnoremap <silent> z <Cmd>lua require("which-key").show("z", {mode = "n", auto = true})
snoremap <silent> <S-Tab> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404229)
tmap <Plug>(cmp.utils.keymap.normalize) 
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_directory(vim.fn.expand("%:p"))
nnoremap <Plug>(nlsp-buf-config) <Cmd>lua require('nlspsettings.command').open_buf_config()
snoremap <silent> <Plug>luasnip-jump-prev <Cmd>lua require'luasnip'.jump(-1)
snoremap <silent> <Plug>luasnip-jump-next <Cmd>lua require'luasnip'.jump(1)
snoremap <silent> <Plug>luasnip-prev-choice <Cmd>lua require'luasnip'.change_choice(-1)
snoremap <silent> <Plug>luasnip-next-choice <Cmd>lua require'luasnip'.change_choice(1)
snoremap <silent> <Plug>luasnip-expand-snippet <Cmd>lua require'luasnip'.expand()
snoremap <silent> <Plug>luasnip-expand-or-jump <Cmd>lua require'luasnip'.expand_or_jump()
noremap <silent> <Plug>luasnip-delete-check <Cmd>lua require'luasnip'.unlink_current_if_deleted()
xnoremap <silent> <Plug>NetrwBrowseXVis :call netrw#BrowseXVis()
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#BrowseX(netrw#GX(),netrw#CheckIfRemote(netrw#GX()))
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v')m'gv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
nnoremap <silent> <C-Left> :vertical resize -2
nnoremap <silent> <C-Down> :resize +2
nnoremap <silent> <C-Up> :resize -2
nnoremap <silent> <M-k> :m .-2==
nnoremap <silent> <M-j> :m .+1==
nnoremap <silent> <C-Right> :vertical resize +2
xnoremap <silent> <M-k> :m '<-2gv-gv
xnoremap <silent> <M-j> :m '>+1gv-gv
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404230)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404224)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404226)
cnoremap <silent> 	 <Cmd>call v:lua.cmp.utils.keymap.set_map(23404219)
inoremap <silent> 	 <Cmd>call v:lua.cmp.utils.keymap.set_map(23404218)
inoremap <silent> <NL> <Cmd>call v:lua.cmp.utils.keymap.set_map(23404217)
cnoremap <expr> <NL> pumvisible() ? "\" : "\<NL>"
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404223)
cnoremap <expr>  pumvisible() ? "\" : "\"
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404215)
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404214)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404213)
cnoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404212)
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404211)
cnoremap <silent> Þ <Nop>
cnoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "c", auto = true})
inoremap <silent> Þ <Nop>
inoremap <silent>  <Cmd>lua require("which-key").show("\18", {mode = "i", auto = true})
inoremap <silent>  <Cmd>ToggleTerm
inoremap  u
inoremap  u
inoremap <silent>  <Cmd>call v:lua.cmp.utils.keymap.set_map(23404225)
inoremap <silent> jj 
inoremap <silent> jk 
inoremap <silent> kj 
let &cpo=s:cpo_save
unlet s:cpo_save
set clipboard=unnamedplus
set cmdheight=2
set completeopt=menuone,noselect
set eventignore=CursorHoldI,CursorHold
set expandtab
set guifont=monospace:h17
set helplang=es
set ignorecase
set mouse=a
set packpath=~/.config/lvim,~/.local/share/lunarvim/site,/etc/xdg/nvim,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/runtime,/usr/lib/nvim,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,/etc/xdg/nvim/after,~/.local/share/lunarvim/lvim,~/.local/share/lunarvim/site/after,~/.config/lvim/after
set pumheight=10
set runtimepath=~/.config/lvim,~/.local/share/lunarvim/site,~/.local/share/lunarvim/site/pack/packer/opt/Comment.nvim,~/.local/share/lunarvim/site/pack/packer/opt/gitsigns.nvim,~/.local/share/lunarvim/site/pack/packer/opt/nvim-ts-context-commentstring,~/.local/share/lunarvim/site/pack/packer/opt/dashboard-nvim,~/.local/share/lunarvim/site/pack/packer/opt/barbar.nvim,~/.local/share/lunarvim/site/pack/packer/opt/which-key.nvim,~/.local/share/lunarvim/site/pack/packer/opt/toggleterm.nvim,~/.local/share/lunarvim/site/pack/packer/start/packer.nvim,~/.local/share/lunarvim/site/pack/*/start/*,/etc/xdg/nvim,/usr/local/share/nvim/site,/usr/share/nvim/site,/usr/share/nvim/runtime,/usr/share/nvim/runtime/pack/dist/opt/matchit,/usr/lib/nvim,~/.local/share/lunarvim/site/pack/*/start/*/after,/usr/share/nvim/site/after,/usr/local/share/nvim/site/after,/etc/xdg/nvim/after,~/.local/share/lunarvim/lvim,~/.local/share/lunarvim/site/after,~/.config/lvim/after
set scrolloff=8
set shiftwidth=4
set shortmess=ifncTFtOolxI
set noshowmode
set showtabline=2
set sidescrolloff=8
set smartcase
set smartindent
set spellfile=~/.config/lvim/spell/en.utf-8.add
set splitbelow
set splitright
set statusline=%{%v:lua.require'lualine'.statusline()%}
set noswapfile
set tabline=%3@BufferlineMainClickHandler@%#BufferInactiveSign#▎\ \ \ \ %#BufferInactive#\ %#BufferInactive#vertex.cpp\ \ \ \ \ %3@BufferlineCloseClickHandler@%#BufferInactive#\ %5@BufferlineMainClickHandler@%#BufferInactiveSign#▎\ \ \ \ %#BufferInactive#\ %#BufferInactive#vertex.hpp\ \ \ \ \ %5@BufferlineCloseClickHandler@%#BufferInactive#\ %7@BufferlineMainClickHandler@%#BufferCurrentSign#▎\ \ \ \ %#DevIconCppCurrent#\ %#BufferCurrent#main.cpp\ \ \ \ \ %7@BufferlineCloseClickHandler@%#BufferCurrent#\ %0@BufferlineMainClickHandler@%#BufferTabpageFill#▎%#BufferTabpageFill#
set tabstop=4
set termguicolors
set timeoutlen=100
set title
set undodir=~/.cache/nvim/undo
set undofile
set updatetime=300
set whichwrap=b,s,<,>,[,],h,l
set window=60
set nowritebackup
" vim: set ft=vim :
