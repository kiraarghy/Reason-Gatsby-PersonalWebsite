import React from 'react'
import Link from 'gatsby-link'
import Header from '../../lib/js/src/components/header.bs.js'
import HeaderImage from '../../lib/js/src/components/headerImage.bs.js'
import Footer from '../../lib/js/src/components/footer.bs.js'
import Content from '../../lib/js/src/components/content.bs.js'
import ProjectWrapper from '../../lib/js/src/components/projects/projectWrapper.bs.js'
import './index.css'

const IndexPage = data => {
  return (
    <div className="page">
      <HeaderImage data={data.data} />
      <Header data={data.data} />
      <Content data={data.data.contentfulAbout.markdown.markdown} />
      <ProjectWrapper data={data.data} />
      <Footer data={data.data} />
    </div>
  )
}

export default IndexPage

export const query = graphql`
  query blah {
    allContentfulProjects {
      edges {
        node {
          projectTItle
          logo {
            file {
              url
            }
            title
            description
          }
          blurb {
            blurb
          }
          url
        }
      }
    }
    contentfulAbout {
      name
      portrait {
        description
        file {
          url
        }
      }
      logo {
        description
        file {
          url
        }
      }
      markdown {
        markdown
      }
      builtUsing {
        title
        file {
          url
        }
      }
    }
  }
`
