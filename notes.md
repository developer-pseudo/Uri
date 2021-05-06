# Elements
* `IsRelative` - flag indicating whether or not the reference is a `relative reference` (as opposed to a `URI`).
* `Scheme` - scheme name, if reference isn't relative.
* `UserInfo` - user information (user name, potentially with authorization information), if any is included.
* `Host` - host name or IP address, if included.
* `Port` - port number, if included.
* `HasPort` - flag indicating whether or not to incldue port number.
* `Path` - sequence of strings:
    * Include absolute path by making first element empty.
* `Query` - query string, if included.
* `Fragment` - fragment string, if included.

## Special disambiguation rules
* `path-abempty`: For a `URI` with an `authority` component, the path must be either empty or absolute (first element empty); otherwise, it wouldn't be possible to distinguish which characters belong to `host` and which belong to the paths first segment.
* `path-noscheme`: A `relative reference` cannot have a path whose first segment contains a colon (`:`) character; otherwise, its string representation would be ambiguous: it would also math a `URI` whose `scheme` is the part of the first segment of the path before the colon

## Notes
* An empty string property indicates that it isn't included in the reference.
* A zero port number is still valid syntatically, so we need to seperate the `HasPort` property to indicate whether or not to include `Port`.
* The `authority` component is only included if `Host` is not empty, regardless of whether or not `UserInfo` is empty, and regardless of `HasPort`.
* If the first element of `Path` is an empty string, it indicates that the path is absolute.